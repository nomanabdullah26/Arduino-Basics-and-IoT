#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10
#define LED_R A2
#define LED_G A5
#define Relay 2

#define Tag_Size 12
#define Known_Card "5473C575"

// Create instances
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() 
{
  // Initiating
  SPI.begin(); // SPI bus
  rfid.PCD_Init(); // MFRC522
  Serial.begin(9600);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(Relay,OUTPUT);
  digitalWrite(Relay,1);
  Serial.print(" Access Control. ");
  Serial.println("Scan Your Card>>");

}

void loop() 
{
  String ID;
  byte Card_tag[Tag_Size];
  
  //Wait until new tag is available
  while (ReadCard(Card_tag,ID)) 
  {
    if (ID == Known_Card)
    {
      Serial.println(" Access Granted!");
      digitalWrite(LED_G,1);
      digitalWrite(LED_R,0);
      digitalWrite(Relay,0);
      // You can write any code here like opening doors, switching on a relay, lighting up an LED, or anything else you can think of.
    }
    else
    {
      Serial.println(" Access Denied!");
      digitalWrite(LED_G,0);
      digitalWrite(LED_R,1);
      digitalWrite(Relay,1);
    }
    
    Serial.print(" ID : ");
    for(byte i =0; i<4;i++)
    {
      Serial.print(Card_tag[i],HEX);
      Serial.print(" ");
    }
    Serial.println();
    
    delay(2000);
    Serial.print(" Access Control ");
    Serial.println("Scan Your Card>>");
    digitalWrite(LED_G,0);
    digitalWrite(LED_R,0);
    digitalWrite(Relay,1 );
  }
}

bool ReadCard(byte* CARD_ID, String & ID) 
{
  // Getting ready for Reading PICCs
  if ( ! rfid.PICC_IsNewCardPresent()) //If a new PICC placed to RFID reader continue
  { 
    return 0;
  }
  if ( ! rfid.PICC_ReadCardSerial()) //Since a PICC placed get Serial and continue
  { 
    return 0;
  }
  ID = "";
  byte card_tag_size = rfid.uid.size;
  for ( byte i = 0; i < card_tag_size; i++) // The MIFARE PICCs that we use have 4 byte UID
  { 
    CARD_ID[i] = rfid.uid.uidByte[i]; //bytes
    ID.concat(String(rfid.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
  }
  ID.toUpperCase(); //convert to uppercase
  rfid.PICC_HaltA(); // Stop reading
  return 1;
}
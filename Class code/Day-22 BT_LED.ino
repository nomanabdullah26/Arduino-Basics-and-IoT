//Assignment: get value from serial
#define LEDR 2
#define LEDG 3
#define LEDB 4
const String keyword[] = {"red" , "green", "blue"};
const String action[] = { "off", "0", "low","on", "1", "high" };

void setup() 
{
  Serial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  digitalWrite(LEDR,0);digitalWrite(LEDG,0);digitalWrite(LEDB,0); //All led off at startup
}

bool serach_engine(String inc, String key, String& match) // raw text , keyword, matched word[output]
{
  bool result=0;
  inc.toLowerCase(); // convert to lower case
  key.toLowerCase(); // convert to lower case
  int index= inc.indexOf(key); // searching for matched keyword index.
  if(index < 0) //if not found, then index = -1
  {
    result = 0; // not found
  }
  else
  {
    result = 1; // match found
    byte len = key.length();    // getting keyword length
    match = inc.substring(index,index+len); //preparing matched result
  }
  return result;
}
 
void token_maker(String col__, String act__, byte& c_, byte& a_)
{
  for(byte i=0; i<3;i++)
  {
    if(col__ == keyword[i])
    {
      c_=i;
      break;
    }
  }
  
  for(byte k=0; k<6;k++)
  {
    if(act__ == action[k])
    {
      a_=k;
      break;
    }
  }
  switch(a_)
  {
    case 0 ... 2 : a_= 0; break;
    case 3 ... 5 : a_= 1; break;
    default      : a_ =0; break; 
  }
}

bool action_center(byte color, byte action)
{
  byte pin;
  Serial.print("Executing.... ");
  switch(color)
  {
    case 0: Serial.print("Red LED   : "); pin = LEDR; break;
    case 1: Serial.print("Green LED : "); pin = LEDG; break;
    case 2: Serial.print("Blue LED  : "); pin = LEDB; break;
  }
  if(action)
  {
    Serial.println("Turned ON");
  }
  else
  {
    Serial.println("Turned OFF");
  }
  digitalWrite(pin,action);  //Writing action to led pin
  Serial.println("-------------------------------------------------------------");
} 

void serial_msg()
{
  Serial.print("Enter any color: ");
  for (byte i=0;i<3;i++)
  {
    Serial.print(keyword[i]);
    if(i <2)
    {
      Serial.print(", ");
    }
  }
  Serial.print(", and write actions like: ");
  for (byte j=0;j<6;j++)
  {
    
    Serial.print(action[j]);
    if(j<5)
    {
      Serial.print(", ");
    }
    else
    {
      Serial.println(" etc.");
    }
    
  }
  Serial.print("Sample command: Turn ");
  Serial.print(action[random(0,5)]);
  Serial.print(" ");
  Serial.print(keyword[random(0,2)]);
  Serial.println(" led.\nThen press enter.\n\n"); 
}

void handle_serial(String & txt)
{
   while(Serial.available()<=0)
  {
    // wait for a while
  }
  if(Serial.available()>0)
  {
    txt = Serial.readStringUntil('\n');
    Serial.println();
    Serial.print("You've entered: ");
    Serial.println(txt);
    Serial.flush();
  }
}

void driver()
{
  String serial_txt="";
  bool res[2];
  String matched[2];
  byte col_, act_;
  bool logical_result=0;

  serial_msg();
  handle_serial(serial_txt);

  for(byte m=0;m<3;m++)
  {
    String matched_0;
    bool x1 =serach_engine(serial_txt, keyword[m],matched_0); //keyword search
    if(x1)
    {
      res[0]= 1;
      matched[0] = matched_0;
      break;
    }
   else
    {
      res[0]=0;
      matched[0] ="";
    }
  }

  for(byte n=0; n<6;n++)
  {
    String matched_1;
    bool x2 = serach_engine(serial_txt, action[n],matched_1); //action search
    if(x2)
    {
      res[1]= 1;
      matched[1] = matched_1;
      break;
    }
    else
    {
      res[1]=0;
      matched[1] ="";
    }
  }
  
  logical_result = (1 && res[0] && res[1]); // building result
  if(logical_result)
  {
    Serial.println("Match found.");
    Serial.print("Color: ");
    Serial.print(matched[0]);
    Serial.print("\nAction: ");
    Serial.println(matched[1]);

    token_maker(matched[0], matched[1], col_, act_);
    action_center(col_, act_);
  } 
  else
  {
    Serial.println("Invalid command!");
  }
}

void loop()
{
  driver();
}

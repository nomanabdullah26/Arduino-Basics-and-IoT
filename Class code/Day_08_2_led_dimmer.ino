int greenled=8;
int redled=3;
int gdelay=1000;
int rdelay=1000;
int j;
int gblink=2;
int rblink=4;
void setup() {
  // put your setup code here, to run once:
pinMode(greenled,OUTPUT);
pinMode(redled,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(j=1; j<=gblink; j=j+1){
digitalWrite(greenled,HIGH);
delay(gdelay);
digitalWrite(greenled,LOW);
delay(gdelay);
  }

for(j=1; j<=rblink; j=j+1){
digitalWrite(redled,HIGH);
delay(rdelay);
digitalWrite(redled,LOW);
delay(rdelay);
  
}

}

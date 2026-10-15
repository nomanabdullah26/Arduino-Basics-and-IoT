 int LDRpin=A0;
 int yellowled=11;
 int greenled=12;
 int LDRvalue;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LDRpin,INPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
LDRvalue = analogRead(LDRpin);
Serial.println(LDRvalue);
delay(200);

if(LDRvalue>150){
digitalWrite(greenled,HIGH);
digitalWrite(yellowled,LOW);
}
if(LDRvalue<150){
digitalWrite(greenled,LOW);
digitalWrite(yellowled,HIGH);
}
}

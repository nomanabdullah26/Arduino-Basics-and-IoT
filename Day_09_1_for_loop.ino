int readpin=A1;
int ledpin=3;
int potvalue;
int dtime=100;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
pinMode(readpin,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
potvalue=analogRead(readpin);
delay(dtime);
while(potvalue>500){
digitalWrite(ledpin,HIGH);
potvalue=analogRead(readpin);
Serial.println(potvalue);
delay(dtime);
}
digitalWrite(ledpin,LOW);
}

int readpin=A0;
int potvalue;
void setup() {
  // put your setup code here, to run once:
pinMode(readpin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potvalue=analogRead(readpin);
delay(10);
Serial.println(potvalue);

}

int readpin=A0;
int potvalue;
float voltage;
void setup() {
  // put your setup code here, to run once:
pinMode(readpin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

potvalue=analogRead(readpin);
delay(10);
voltage = (5./1023.)*potvalue;
Serial.println(potvalue);
Serial.println(voltage);
delay(2000);
}

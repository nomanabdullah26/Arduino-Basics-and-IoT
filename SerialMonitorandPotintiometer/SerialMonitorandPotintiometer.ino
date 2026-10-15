int readpin= A0;
int  portvalue;
float voltage;

void setup() {
  // put your setup code here, to run once:
pinMode(readpin,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
portvalue= analogRead(readpin);
delay(10);

voltage =  (5./1023.)*portvalue;
Serial.println(portvalue);
Serial.println(voltage);
delay(200);

}


int LEDPin=5;
int delay1=1000;
int delay2=2000;
void setup() {
  // put your setup code here, to run once:
pinMode(LEDPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LEDPin,HIGH);
delay(delay1);
digitalWrite(LEDPin,LOW);
delay(delay1);

digitalWrite(LEDPin,HIGH);
delay(delay1);
digitalWrite(LEDPin,LOW);
delay(delay1);

digitalWrite(LEDPin,HIGH);
delay(delay1);
digitalWrite(LEDPin,LOW);
delay(delay1);

digitalWrite(LEDPin,HIGH);
delay(delay2);
digitalWrite(LEDPin,LOW);
delay(delay2);

digitalWrite(LEDPin,HIGH);
delay(delay2);
digitalWrite(LEDPin,LOW);
delay(delay2);

digitalWrite(LEDPin,HIGH);
delay(delay2);
digitalWrite(LEDPin,LOW);
delay(delay2);

digitalWrite(LEDPin,HIGH);
delay(delay1);
digitalWrite(LEDPin,LOW);
delay(delay1);

digitalWrite(LEDPin,HIGH);
delay(delay1);
digitalWrite(LEDPin,LOW);
delay(delay1);

digitalWrite(LEDPin,HIGH);
delay(delay1);
digitalWrite(LEDPin,LOW);
delay(delay1);

delay(1000);
}

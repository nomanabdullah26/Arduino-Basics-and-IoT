int LEDPin=6;
int delay1=500;
int delay2=500;
void setup() {
// put your setup code here, to run once:
pinMode(LEDPin, OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
analogWrite(LEDPin,255);
delay(delay1);
analogWrite(LEDPin,0);
delay(delay2);
}

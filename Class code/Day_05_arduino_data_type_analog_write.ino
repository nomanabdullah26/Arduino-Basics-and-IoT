int ledpin=3;
int dutycycle1=255;
int dutycycle2=200;
int dutycycle3=150;
int dutycycle4=100;
int dutycycle5=50;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(ledpin,dutycycle1);
delay(100);
analogWrite(ledpin,utycycle2);
delay(100);
analogWrite(ledpin,utycycle3);
delay(100);
analogWrite(ledpin,dutycycle4);
delay(100);
analogWrite(ledpin,dutycycle5);
delay(100);
}

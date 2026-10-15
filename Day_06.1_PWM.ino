int pushbutton=5;
int buttonstate;
int ledpin=8;
void setup() {
  // put your setup code here, to run once:
pinMode(pushbutton,INPUT);
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonstate=digitalRead(pushbutton);
delay(10);
digitalWrite(ledpin,buttonstate);
delay(100);
}

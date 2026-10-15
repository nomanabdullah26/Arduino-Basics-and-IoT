int ledstate=0;
int ledpin=12;
int pushpin=10;
int pushnew;
int pushold=1;
int dtme=200;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(pushpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
pushnew = digitalRead(pushpin);
Serial.println(pushnew);
delay(10);
if(pushold==0 && pushnew==1){
if(ledstate==0){
digitalWrite(ledpin,HIGH);
ledstate=1;
}
else{
digitalWrite(ledpin,LOW);
ledstate=0;
}
}
pushold=pushnew;
}

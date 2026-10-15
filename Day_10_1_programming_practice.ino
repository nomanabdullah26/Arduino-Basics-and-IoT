int ledpin[] = {8,9,10,11,12};
int pincount=5;
int j;
int potpin=A1;
int potvalue;
int lastpotvalue;
void setup() {
  // put your setup code here, to run once:
  for(j=0; j<pincount; j++){
   pinMode(ledpin[j],OUTPUT);
  }
pinMode(potpin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potvalue = analogRead(potpin)/204;
Serial.println(potvalue);
delay(800);

//--------if statement--------------
if(potvalue==0){
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED0 ON");
}

if(potvalue==1){
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED1 ON");
}

if(potvalue==2){
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED2 ON");
}

if(potvalue==3){
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED3 ON");
}
if(potvalue==4){
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED4 ON");
}
if(potvalue==5){

Serial.println("ERROR");
}
//-----------switch case statement---------------
if(potvalue!=lastpotvalue){
switch(potvalue){
case 0:
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED0 ON");
break;
case 1:
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED1 ON");
break;
case 2:
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED2 ON");
break;
case 3:
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED3 ON");
break;
case 4:
digitalWrite(ledpin[potvalue],HIGH);
Serial.println("LED4 ON");
break;
digitalWrite(ledpin[potvalue],HIGH);
default:
Serial.println("ERROR");

}
}
lastpotvalue = potvalue;
}

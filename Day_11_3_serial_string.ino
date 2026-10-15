int redled=10;
int yellowled=11;
int greenled=12;
String mycolor;
String msg1 = "Write the color of the LED:  ";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg1);
delay(100);
while(Serial.available()==0){

}
mycolor = Serial.readString();
if(mycolor=="RED\r\n"){  
digitalWrite(redled,HIGH);
digitalWrite(yellowled,LOW);
digitalWrite(greenled,LOW);
}
if(mycolor=="YELLOW\r\n"){
digitalWrite(redled,LOW);
digitalWrite(yellowled,HIGH);
digitalWrite(greenled,LOW);
}
if(mycolor=="GREEN\r\n"){
digitalWrite(redled,LOW);
digitalWrite(yellowled,LOW);
digitalWrite(greenled,HIGH);
}

}

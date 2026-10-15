float radius;
int ledpin=10;
float pi=3.14;
int j;
int dtime=500;
String msg1 = "What is the radius of your circle? ";
String msg2 = "Your radius is: ";
String msg3 = "Your Circle area is: ";
float area;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg1);
delay(100);
while(Serial.available()==0){

}
radius = Serial.parseFloat();
Serial.print(msg2);
Serial.println(radius);
area = pi * radius * radius;
Serial.print(msg3);
Serial.println(area);
}

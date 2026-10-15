
int a=1;
int p=5;
int q=6;
int r;
String mystring= "*";
String mystring1= "Multiplication of ";
String mystring2= " Equal to ";
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
r = p*q;
Serial.print(mystring1);
Serial.print(p);
Serial.print(mystring);
Serial.print(q);
Serial.print(mystring2);
Serial.println(r);
delay(2000);
}
Multiplication of p=5 into q=6 Equal to r=30
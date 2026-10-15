int ledpin[] = {8,9,10,11,12};
int pinnumber=5;
int j;
void setup() {
  // put your setup code here, to run once:
  for(j=0; j<pinnumber; j=j+1){
pinMode(ledpin[j],OUTPUT);
  }
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
for(j=0; j<pinnumber; j=j+1){
digitalWrite(ledpin[j],HIGH);
delay(1000);
digitalWrite(ledpin[j],LOW);
}
for(j=pinnumber-1; j>=0; j=j-1){
digitalWrite(ledpin[j],HIGH);
delay(1000);
digitalWrite(ledpin[j],LOW);
}

}

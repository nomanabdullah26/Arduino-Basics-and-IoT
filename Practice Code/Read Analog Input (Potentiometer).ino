
int potPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(potPin);         // 0–1023
  int brightness = map(value, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  Serial.println(value);
  delay(10);
}
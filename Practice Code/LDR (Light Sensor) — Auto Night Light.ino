int ldrPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int light = analogRead(ldrPin);
  if (light < 500) {
    digitalWrite(ledPin, HIGH);  // Dark → LED on
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
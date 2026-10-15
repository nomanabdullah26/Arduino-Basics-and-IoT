int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 262);  // C4
  delay(300);
  tone(buzzerPin, 294);  // D4
  delay(300);
  tone(buzzerPin, 330);  // E4
  delay(300);
  noTone(buzzerPin);
  delay(1000);
}
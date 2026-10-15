volatile int count = 0;
int buttonPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}

void buttonISR() {
  count++;
}

void loop() {
  Serial.print("Presses: ");
  Serial.println(count);
  delay(500);
}
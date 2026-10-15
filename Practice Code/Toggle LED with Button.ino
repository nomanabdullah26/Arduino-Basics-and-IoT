int buttonPin = 2;
int ledPin = 13;
bool ledState = false;
int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int currentState = digitalRead(buttonPin);
  if (currentState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(50);  // Debounce
  }
  lastButtonState = currentState;
}
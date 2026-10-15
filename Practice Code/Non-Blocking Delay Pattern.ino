unsigned long lastTime = 0;
const unsigned long interval = 1000;

void loop() {
  if (millis() - lastTime >= interval) {
    lastTime = millis();
    // Do something every 1 second
  }
}
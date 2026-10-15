void setup() {
  Serial.begin(9600);
  Serial.println("Arduino ready!");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    Serial.print("Received: ");
    Serial.println(c);
  }
}
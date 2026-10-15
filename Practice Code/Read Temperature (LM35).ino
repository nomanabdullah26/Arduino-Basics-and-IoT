int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0 / 1024.0;
  float tempC = voltage * 100;    // LM35: 10mV per °C
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" C / ");
  Serial.print(tempF);
  Serial.println(" F");
  delay(1000);
}
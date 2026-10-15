const int ledPin = 9;        // Pin connected to the LED
const int potPin = A1;       // Pin connected to the potentiometer
int mode = 0;                // Variable to store the current mode

void setup() {
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  Serial.begin(9600);        // Start serial communication for debugging
}

void loop() {
  int sensorValue = analogRead(potPin);   // Read the potentiometer value
  mode = map(sensorValue, 0, 1023, 0, 4); // Map the value to a range of 0 to 4

  switch (mode) {
    case 0:
      digitalWrite(ledPin, LOW);          // Mode 0: LED off
      Serial.println("Mode 0: LED off");
      break;

    case 1:
      digitalWrite(ledPin, HIGH);         // Mode 1: LED on
      Serial.println("Mode 1: LED on");
      break;

    case 2:
      blinkLED(200);                      // Mode 2: LED blinks slowly
      Serial.println("Mode 2: LED blinking slowly");
      break;

    case 3:
      blinkLED(100);                      // Mode 3: LED blinks fast
      Serial.println("Mode 3: LED blinking fast");
      break;

    case 4:
      digitalWrite(ledPin, LOW);          // Mode 4: LED off (default case)
      Serial.println("Mode 4: LED off");
      break;

    default:
      digitalWrite(ledPin, LOW);          // Default case: LED off
      Serial.println("Default: LED off");
      break;
  }

  delay(100);  // Small delay to make the mode switch smoother
}

// Function to blink the LED with a specified interval
void blinkLED(int interval) {
  digitalWrite(ledPin, HIGH);
  delay(interval);
  digitalWrite(ledPin, LOW);
  delay(interval);
}

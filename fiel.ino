
const int sensorPin = A0;

const int ledPins[] = {1, 2, 3, 4, 5, 6, 7, 8};
const int numLeds = 8;

// Workshop challenge: calibrate these values!
int sensorMin = 180;
int sensorMax = 450;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int reading = analogRead(sensorPin);

  // Print the raw sensor reading for investigation.
  Serial.println(reading);

  // Convert the sensor range into a level from 0 to 8.
  int level = map(reading, sensorMin, sensorMax, 0, numLeds);
  level = constrain(level, 0, numLeds);

  // Turn on the corresponding number of LEDs.
  for (int i = 0; i < numLeds; i++) {a
    digitalWrite(ledPins[i], i < level ? HIGH : LOW);
  }

  delay(100);
}

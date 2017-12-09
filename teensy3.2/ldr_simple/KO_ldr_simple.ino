// Settings and pins
const int ledPin = 3;
const int ldrPin = A0;
int ldrThreshold = 300;

// Value declarations
int ldrValue = 0;
boolean light = false;
boolean lastLight = false;
boolean outputLight = false;
int offTime, onTime;
int ldrRate = 200;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Get values
  ldrValue = analogRead(ldrPin);

  // Analyze values for the LDR being covered and uncovered
  // Stores the time in milliseconds at which the event occurred
  ldrDetect();

  // Switches the light at the detected rate
  if (millis() % ldrRate == 0) {
    outputLight = !outputLight;
  }

  // Also printing 0 and 1023 to prevent the Arduino IDE from scaling the plotting graph...
  //  Serial.print("0 ");
  //  Serial.print(ldrValue);
  //  Serial.print(" ");
  //  Serial.print(ldrThreshold);
  //  Serial.println(" 1023");

  // Output the result
  delay(1);
  digitalWrite(ledPin, outputLight);
}

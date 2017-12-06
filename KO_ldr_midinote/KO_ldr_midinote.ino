#include "smoothing.h"

// Settings and pins
const int ledPin = 3;
const int ledPinOnboard = 13;
const int ldrPin = A0;
const boolean printLDR = 0;

// LDR Values
int ldrValue = 0;
int averageLight = 0;
int ldrThreshold = 0;

// Create new smoothing instance
ValueSmoothing ldrVal;

// MIDI
const int channel = 1;

// LED
boolean light = false;
boolean lastLight = false;
boolean outputLight = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinOnboard, OUTPUT);

  // For debugging purposes
  Serial.begin(9600);

  averageLight = calibrateLDR(10, ldrPin);
}

void loop() {
  // Read and smooth ldr values
  ldrValue = ldrVal.smooth(analogRead(ldrPin));
  // -- -- -- -- -- -- -- -- -- -- //

  ldrSwitch();
  
  if (printLDR) {
    Serial.print("0 ");
    Serial.print(ldrValue);
    Serial.print(" ");
    Serial.print(ldrThreshold);
    Serial.println(" 1024");
  }

  // -- -- -- -- -- -- -- -- -- -- //
  while (usbMIDI.read()) {
  }
  delay(1);
  digitalWrite(ledPin, light);
}

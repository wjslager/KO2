#include "smoothing.h"

// ==== ==== ==== ==== V A L U E S ==== ==== ==== ==== ==== //

// Settings and pins
const int ledPin = 3;
const int ledPinOnboard = 13;
const int ldrPin = A0;
const boolean printLDR = false;

// LDR Values
int ldrValue = 0;
int averageLight = 0;
int ldrThreshold = 0;
// Create new smoothing instance
ValueSmoothing ldrVal;

// Recording values
boolean lastLight;
int timeStartRec = 0;
int timeSinceLastMotion;
int playbackPos = 0;
//int recordedLength = 1000;
int recordedValues[1000];

// Output values
boolean light = false;
boolean outputLight = false;
boolean recording = false;

// ==== ==== ==== ==== S E T U P ==== ==== ==== ==== ==== //

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinOnboard, OUTPUT);

  // For debugging purposes
  Serial.begin(9600);

  averageLight = calibrateLDR(10, ldrPin);
}

// ==== ==== ==== ==== L O O P ==== ==== ==== ==== ==== //

void loop() {
  // ---- ---- INPUT ---- ----  //
  
  // Read and smooth ldr values
  ldrValue = ldrVal.smooth(analogRead(ldrPin));
  
  // ---- ---- TRANSFORMATION ---- ----  //
  
  // Start and stop recording
  dynamicRecording();
  
  // Record of playback motions
  recordMotion();
  
  if (printLDR) {
    Serial.print("0 ");
    Serial.print(ldrValue);
    Serial.print(" ");
    Serial.print(ldrThreshold);
    Serial.println(" 1024");
  }

  // ---- ---- OUTPUT ---- ----  //
  
  delay(1);
  digitalWrite(ledPin, outputLight);
  digitalWrite(ledPinOnboard, recording);
}

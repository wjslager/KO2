#include "SparkFunLIS3DH.h"
#include "Wire.h"

// Bare sensor values
float sensX = 0;
float sensY = 0;
float sensZ = 0;

LIS3DH xyzSens;

void setup() {
  Serial.begin(9600);
  delay(1000);

  xyzSens.begin();
}


void loop()
{
  // Read and store the sensor values
  sensX = xyzSens.readFloatAccelX();
  sensY = xyzSens.readFloatAccelY();
  sensZ = xyzSens.readFloatAccelZ();

  //  printXYZ();
  plotXYZ();

  delay(100);
}




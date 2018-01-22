#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "SparkFunLIS3DH.h"
#include "floatsmoothing.h"

// GUItool: begin automatically generated code
AudioSynthWaveform       fm_modulator;   //xy=185.01040649414062,289.99999237060547
AudioMixer4              fm_mod_mix;     //xy=428.0104064941406,303.99999237060547
AudioSynthWaveformSineModulated fm_carrier;     //xy=643.0104064941406,314.99999237060547
AudioOutputAnalog        dac1; //xy=1038.0104064941406,314.99999237060547
AudioConnection          patchCord1(fm_modulator, 0, fm_mod_mix, 0);
AudioConnection          patchCord2(fm_mod_mix, fm_carrier);
AudioConnection          patchCord3(fm_carrier, dac1);
// GUItool: end automatically generated code

LIS3DH xyzSens;

// XYZ values
float sensX = 0;
float sensY = 0;
float sensZ = 0;
float smoothX = 0;
float smoothY = 0;
float smoothZ = 0;

float pitch = 0;

FloatSmoothing smX(0.01);
FloatSmoothing smY(0.1);
FloatSmoothing smZ(0.01);

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  Serial.begin(9600);
  delay(1000);
  xyzSens.begin();

  /* ==== AUDIO ==== */
  AudioMemory(16);

  fm_modulator.begin(1, 70, WAVEFORM_SINE);
  fm_modulator.frequency(mtof(52));

  fm_mod_mix.gain(0, 0.5);

  fm_carrier.frequency(mtof(40));
  fm_carrier.amplitude(1);
}

void loop()
{
  // Read and store the sensor values
  sensX = xyzSens.readFloatAccelX();
  sensY = xyzSens.readFloatAccelY();
  sensZ = xyzSens.readFloatAccelZ();
  smoothX = smX.smooth(sensX);
  smoothY = smX.smooth(sensY);
  smoothZ = smX.smooth(sensZ);

  pitch = mtof(60 + (12 * smoothX));

  fm_modulator.frequency(pitch);
  fm_mod_mix.gain(0, smoothY * 3);
  fm_carrier.frequency(pitch * (2 + smoothZ));

  fm_carrier.amplitude(clip(smoothX + smoothY + smoothZ, 0, 1));

  printXYZ();
  delay(1);
}

void printXYZ()
{
  Serial.print(sensX);
  Serial.print(" ");
  Serial.print(sensY);
  Serial.print(" ");
  Serial.print(sensZ);
  Serial.print(" ");
  Serial.print(smoothX);
  Serial.print(" ");
  Serial.print(smoothY);
  Serial.print(" ");
  Serial.println(smoothZ);
}


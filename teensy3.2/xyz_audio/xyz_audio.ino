#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "SparkFunLIS3DH.h"
#include "above.h"

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

void setup()
{
  Serial.begin(9600);
  xyzSens.begin();

  /* ==== AUDIO ==== */
  AudioMemory(16);
  
  fm_modulator.begin(1, 70, WAVEFORM_SINE);
  fm_modulator.frequency(mtof(52));

  // Modulator attenuation
  fm_mod_mix.gain(0, 0.5);

  fm_carrier.frequency(mtof(40));
  fm_carrier.amplitude(1);


  // Turn the led on to prove the teensy still runs
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop()
{
  // Read and store the sensor values
  sensX = xyzSens.readFloatAccelX();
  sensY = xyzSens.readFloatAccelY();
  sensZ = xyzSens.readFloatAccelZ();

  fm_modulator.frequency(mtof(52 + (12 * sensX)));
  fm_mod_mix.gain(0, sensY);
  fm_carrier.frequency(mtof(40 + (12 * sensX)));

  Serial.print(sensX);
  Serial.print(" ");
  Serial.print(sensY);
  Serial.print(" ");
  Serial.println(sensZ);
}

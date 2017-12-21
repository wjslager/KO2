#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;
AudioOutputAnalog        dac1;
AudioConnection          patchCord1(sine1, dac1);
// GUItool: end automatically generated code

void setup() {
  AudioMemory(4);

  sine1.frequency(440);
  sine1.amplitude(0.1);
}

void loop() {
}

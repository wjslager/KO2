#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "sequencer.h"

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=99.01040649414062,159.01040744781494
AudioEffectDelay         delayFX;         //xy=799.0104522705078,249.01040649414062
AudioMixer4              delayInput;         //xy=959.010368347168,378.0104179382324
AudioMixer4              master;         //xy=982.0104103088379,139.0104284286499
AudioOutputAnalog        dac;           //xy=1182,140.99999713897705
AudioConnection          patchCord1(waveform1, 0, master, 0);
AudioConnection          patchCord2(waveform1, 0, delayInput, 2);
AudioConnection          patchCord3(delayFX, 0, master, 3);
AudioConnection          patchCord4(delayFX, 0, delayInput, 0);
AudioConnection          patchCord5(delayFX, 1, delayInput, 1);
AudioConnection          patchCord6(delayInput, delayFX);
AudioConnection          patchCord7(master, dac);
// GUItool: end automatically generated code

float pw = 0;
double pwInc = 0.00001;

// Initialize a new sequencer running at 200ms per trigger
Sequencer pwmSeq(200);

void setup() {
  AudioMemory(128);
  waveform1.begin(1, 70, WAVEFORM_PULSE);
  delayFX.delay(0, 230);
  delayInput.gain(0, 0.7); // Main FB
  delayInput.gain(1, 0);
  delayInput.gain(2, 0.2); // Delay input gain
  master.gain(0, 1);
  master.gain(3, 1);

  Serial.begin(9600);
}

void loop() {
  waveform1.amplitude(millis() % 500 > 200);
  waveform1.frequency(mtof(40));
  waveform1.pulseWidth(pw);

  // Reverse the PWM inc if it reached 0 or 1;
  if (pw > 1 || pw < 0) pwInc = -pwInc;
  pw += pwInc;

  if (pwmSeq.checkTrigger()) {
    Serial.print("trigger ");
    Serial.println(pwmSeq.triggerCount);
  }
}

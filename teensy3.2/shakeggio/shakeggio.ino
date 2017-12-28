#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "sequencer.h"

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=207.01040267944336,98.01041412353516
AudioEffectEnvelope      envelope1;      //xy=530.0103607177734,105.01042366027832
AudioMixer4              master;         //xy=939.0104598999023,127.01043319702148
AudioOutputAnalog        dac;           //xy=1171.0000305175781,129.9999942779541
AudioConnection          patchCord1(waveform1, envelope1);
AudioConnection          patchCord2(envelope1, 0, master, 0);
AudioConnection          patchCord3(master, dac);
// GUItool: end automatically generated code

float pw = 0;
double pwInc = 0.00001;
int arp1[] = {0, 3, 2, 7, 5, 8, 5, 2};
int noteInd = 0;

// Initialize a new sequencer running at 200ms per trigger
Sequencer pwmSeq(200);

void setup() {
  Serial.begin(9600);
 
  AudioMemory(128);
  
  waveform1.begin(1, 70, WAVEFORM_PULSE);
  waveform1.frequency(mtof(60));
  master.gain(0, 1);

  envelope1.sustain(0);
  envelope1.decay(100);
}

void loop() {
  waveform1.pulseWidth(pw);

  // Reverse the PWM inc if it reached 0 or 1;
  if (pw > 1 || pw < 0) pwInc = -pwInc;
  pw += pwInc;

  if (pwmSeq.checkTrigger()) {
    waveform1.frequency(mtof(60 + arp1[pwmSeq.triggerCount%8]));
    envelope1.noteOn();
    pw = 0.5;
  }
}

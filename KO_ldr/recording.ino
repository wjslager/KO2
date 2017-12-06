void recordMotion() {
  if (recording) {
    // Display the users actions using the led
    outputLight = light;

    // Record LDR values
    // One sample per 10ms
    if (millis() % 10 == 0) {
      // Take a sample
      recordedValues[playbackPos] = light;
      // Advance one step
      playbackPos++;
      Serial.print("Sampled LDR value at ");
      Serial.println(playbackPos++);
    }
    playbackPos = playbackPos % 1000;
  }
  else {
    // Display the recorded motion
    outputLight = recordedValues[playbackPos];
    //    Serial.println(recordedValues[playbackPos]);
    if (millis() % 10 == 0) {
      playbackPos++;
      playbackPos = playbackPos % 1000;
      Serial.print("Playing recorded value at ");
      Serial.println(playbackPos++);
    }
  }
}

void dynamicRecording() {
  // Automatically starts recording when a 'light on' is detected
  // Will stop recording ~1000ms after the last 'light off'

  switch (lightSwitch()) {
    case 1:                           // Light on
      if (!recording) {
        // Set recording to true and save the starttime
        playbackPos = 0;
        recording = true;
        timeStartRec = millis();
      }
    case -1:                          // Light off
      timeSinceLastMotion = millis();
    default:                          // No change
      // If the light is off, start a countdown of 1000ms to stop recording
      if (!light) {
        if ((millis() - timeSinceLastMotion) >= 1000) {
          // Stop recording, set playbackhead at 0
          recording = false;
        }
      }
  }
}

int lightSwitch() {
  // Detects 'light on' and 'light off'
  if (ldrValue > ldrThreshold) {
    light = false;
  } else {
    light = true;
  }

  if (light != lastLight) {
    if (light) {
      // Light turned on
      lastLight = light;
      //      Serial.println("1");
      return 1;
    }
    else {
      // Light turned off
      lastLight = light;
      //      Serial.println("2");
      return -1;
    }
  }
  else {
    // No change
    lastLight = light;
    return 0;
  }
}


int ldrSwitch() {
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
      Serial.println("Note on");
      usbMIDI.sendNoteOn(60, 99, channel);
      return 1;
    }
    else {
      // Light turned off
      lastLight = light;
      Serial.println("Note off");
      usbMIDI.sendNoteOff(60, 0, channel);
      return -1;
    }
  }
  else {
    // No change
    lastLight = light;
    return 0;
  }
}

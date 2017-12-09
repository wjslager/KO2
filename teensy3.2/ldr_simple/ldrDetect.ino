int ldrDetect() {
  // Dumb the data down to just on/off
  if (ldrValue > ldrThreshold) {
    light = false;
  } else {
    light = true;
  }

  // Detects 'light on' and 'light off'
  if (light != lastLight) {
    if (light) {
      Serial.println("LDR covered");
      lastLight = light;
      onTime = millis();
      return 0;
    }
    else {
      Serial.println("LDR uncovered");
      lastLight = light;
//      offTime = millis();
      ldrRate = millis() - onTime;
      return 0;
    }
  }
  else {
    // No change in LDR values
    lastLight = light;
    return 0;
  }
}

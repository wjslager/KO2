int calibrateLDR(int samples, int inputPin) {
  // Ran at boot to check the average light brightness
  // Makes sure the teensy should function in most circumstances
  int testedLight = 0;
  int averageValue = 0;
  
  // Take samples of the LDR values
  for (int i = 0; i < samples; i++) {
    ldrValue = analogRead(inputPin);
    testedLight += ldrValue;
    delay(10);
  }

  // Divide by the total no of samples
  
  averageValue = testedLight / samples;
  ldrThreshold = averageValue * 0.4;
  return averageValue;
}

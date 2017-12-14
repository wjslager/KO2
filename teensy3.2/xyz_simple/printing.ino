void printXYZ() {
  Serial.print(" X = ");
  Serial.print(sensX, 3);
  Serial.print(" Y = ");
  Serial.print(sensY, 3);
  Serial.print(" Z = ");
  Serial.println(sensZ, 3);
}

void plotXYZ() {
  Serial.print(-1);
  Serial.print(" ");
  Serial.print(sensX, 4);
  Serial.print(" ");
  Serial.print(sensY, 4);
  Serial.print(" ");
  Serial.print(sensZ, 4);
  Serial.print(" ");
  Serial.println(1);
}

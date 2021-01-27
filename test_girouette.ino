void setup() {
  Serial.begin(115200);
  analogRead(A0);
}

void loop() {
  static int v_mini = 2000;
  static int v_maxi = 0;

  delay(500);
  
  int sensorValue = analogRead(A0);
  
  Serial.print(sensorValue);
  if (sensorValue < v_mini) v_mini = sensorValue;
  if (sensorValue > v_maxi) v_maxi = sensorValue;
  Serial.print("\t"); Serial.print(v_mini); Serial.print(" - "); Serial.println(v_maxi);
  
}
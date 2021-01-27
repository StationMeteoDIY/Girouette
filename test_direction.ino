

void setup() {
  Serial.begin(115200);
  analogRead(A0);
}

void loop() {
  static String old_wd;

  delay(500);
  
  int sensorValue = analogRead(A0);
  

  float dirvent = sensorValue / 3.3 ;
  String wd = "other";
  
  if(dirvent > 8 &&  dirvent < 14 ){
    wd = "W";
  }
  if(dirvent > 17 &&  dirvent < 23 ){
    wd = "NW";
  }
  if(dirvent > 28 &&  dirvent < 35 ){
    wd = "N";
  }
  if(dirvent > 56 &&  dirvent < 62 ){
    wd = "SW";
  }
  if(dirvent > 91 &&  dirvent < 99 ){
    wd = "NE";
  }
  if(dirvent > 124 &&  dirvent < 154 ){
    wd = "S";
  }
  if(dirvent > 188 &&  dirvent < 201 ){
    wd = "SE";
  }
  if(dirvent > 224 &&  dirvent < 240 ){
    wd = "E";
  }    

  if(wd == "other") {
    wd = old_wd;
  } else {
    old_wd = wd;
  }
  
  Serial.print("Wind Direction: ");
  Serial.println(wd);
  
}
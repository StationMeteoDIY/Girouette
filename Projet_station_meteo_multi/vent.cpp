#include <Arduino.h>
#include "mqtt.h"

const byte ventPin     = A0;    // PIN de connexion de capteur girouette.
int idxVent            = 2;     // Index du Device de la girouette.

void init_vent() {
  // Initialisation.
  analogRead(ventPin);          // Initialisation de la lecture analogique.
}


void getDirVent (){
  static String old_wd;
  int sensorValue = analogRead(ventPin);
  
  float dirvent = sensorValue / 3.3 ;
  String wd = "other";
  int angw  = 0;
  
  if(dirvent > 8 &&  dirvent < 14 ){
    wd = "W";
    angw  = 270;
  }
  if(dirvent > 17 &&  dirvent < 23 ){
    wd = "NW";
    angw  = 315;
  }
  if(dirvent > 28 &&  dirvent < 35 ){
    wd = "N";
    angw  = 0;
  }
  if(dirvent > 56 &&  dirvent < 62 ){
    wd = "SW";
    angw  = 225;
  }
  if(dirvent > 91 &&  dirvent < 99 ){
    wd = "NE";
    angw  = 45;
  }
  if(dirvent > 124 &&  dirvent < 154 ){
    wd = "S";
    angw  = 180;
  }
  if(dirvent > 188 &&  dirvent < 201 ){
    wd = "SE";
    angw  = 135;
  }
  if(dirvent > 224 &&  dirvent < 240 ){
    wd = "E";
    angw  = 90;
  }    

  if(wd == "other") {
    wd = old_wd;
  } else {
    old_wd = wd;
  }

  // envoi des données.
  if (idxVent != 0) {
    // Envoi dans la console de debug.
    Serial.print("Vent venant de : "); Serial.print(wd); 
    Serial.print(" soit à "); Serial.print(String(angw)); Serial.println("° ");
    
    // Envoi des données à Domoticz
    String svalue = String(angw) + ";" + wd + ";0;0;22;24";
    SendData("udevice", idxVent, 0, svalue);
  }

}

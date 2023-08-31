#include "wifiManager.h"
#include "FirebaseESP8266.h"

#define HOST "test8266-d9607-default-rtdb.firebaseio.com"
#define TOKEN "02DJSBVWTUxiytzpMxJ42fjCpPUbEsFQupvtcTkJ"

FirebaseData database;

bool foco;

#define fc D1

void setup() {
  conectarWifi();

  Firebase.begin(HOST, TOKEN);
  Firebase.reconnectWiFi(true);

  pinMode(fc, OUTPUT);
}

void loop() {

  Firebase.getBool(database,F("/Casa/foco"), &foco) ? foco ? "true" : "false" : database.errorReason().c_str();

  Serial.print(foco);
  if(foco == 1){
    digitalWrite(fc, 0);
   }else{
    digitalWrite(fc, 1);
   }
}

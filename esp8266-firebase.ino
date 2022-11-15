#include "wifiManager.h"     
#include <FirebaseESP8266.h>      

#define API_KEY "a1Se8grBKEpga12uWOacQYdtNLYBsu0bF9tetWTq"

#define DATABASE_URL "test-flutterbase-default-rtdb.firebaseio.com"

String ruta = "casa";

FirebaseData fbdo;

bool foco;

#define led D7

void setup()
{

  conectarWifi();
  pinMode(led, OUTPUT);
 
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  
  Firebase.begin(DATABASE_URL, API_KEY);

  Firebase.reconnectWiFi(true);
 
}

void loop()
{
      Serial.printf("Get bool ref... %s\n", Firebase.getBool(fbdo, F("/casa/foco"), &foco) ? foco ? "true" : "false" : fbdo.errorReason().c_str());
      if(foco){
       digitalWrite(led, HIGH); 
      }else{
       digitalWrite(led, LOW);
      }
}

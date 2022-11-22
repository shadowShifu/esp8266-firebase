#include "wifiManager.h"     
#include <FirebaseESP8266.h>      

#define API_KEY "a1Se8grBKEpga12uWOacQYdtNLYBsu0bF9tetWTq"

#define DATABASE_URL "test-flutterbase-default-rtdb.firebaseio.com"

FirebaseData fbdo;

bool vent;

#define ventilador D7

void setup()
{

  conectarWifi();
  pinMode(ventilador, OUTPUT);
 
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  
  Firebase.begin(DATABASE_URL, API_KEY);

  Firebase.reconnectWiFi(true);
 
}

void loop()
{
      Firebase.getBool(fbdo, F("/invernadero/ventilador"), &vent) ? vent ? "true" : "false" : fbdo.errorReason().c_str();

      if(vent){
       Serial.print(vent);
      }else{
       Serial.print(vent);
      }

}

#include "wifiManager.h"     
#include <FirebaseESP8266.h>      

#define API_KEY "a1Se8grBKEpga12uWOacQYdtNLYBsu0bF9tetWTq"

#define DATABASE_URL "test-flutterbase-default-rtdb.firebaseio.com"

String ruta = "casa";

FirebaseData fbdo;

bool foco;
bool foco2;
bool foco3;
bool foco4;
bool puerta;

#define led D7
#define led2 D6
#define led3 D5
#define led4 D2
#define chapa D1

void setup()
{

  conectarWifi();
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(chapa, OUTPUT);
 
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  
  Firebase.begin(DATABASE_URL, API_KEY);

  Firebase.reconnectWiFi(true);

  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(chapa, LOW);
 
}

void loop()
{
      Firebase.getBool(fbdo, F("/casa/foco"), &foco) ? foco ? "true" : "false" : fbdo.errorReason().c_str();
      Firebase.getBool(fbdo, F("/casa/foco2"), &foco2) ? foco2 ? "true" : "false" : fbdo.errorReason().c_str();
      Firebase.getBool(fbdo, F("/casa/foco3"), &foco3) ? foco3 ? "true" : "false" : fbdo.errorReason().c_str();
      Firebase.getBool(fbdo, F("/casa/foco4"), &foco4) ? foco4 ? "true" : "false" : fbdo.errorReason().c_str();
      Firebase.getBool(fbdo, F("/casa/puerta"), &puerta) ? puerta ? "true" : "false" : fbdo.errorReason().c_str();

      if(foco){
       digitalWrite(led, HIGH); 
      }else{
       digitalWrite(led, LOW);
      }

      if(foco2){
       digitalWrite(led2, HIGH); 
      }else{
       digitalWrite(led2, LOW);
      }

      if(foco3){
       digitalWrite(led3, HIGH); 
      }else{
       digitalWrite(led3, LOW);
      }

      if(foco4){
       digitalWrite(led4, HIGH); 
      }else{
       digitalWrite(led4, LOW);
      }

      if(puerta){
       digitalWrite(chapa, HIGH); 
      }else{
       digitalWrite(chapa, LOW);
      }

}

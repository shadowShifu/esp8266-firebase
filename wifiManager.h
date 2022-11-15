#include <ESP8266WiFi.h>

#include <strings_en.h>
#include <WiFiManager.h>


#include <DNSServer.h>
#include <ESP8266WebServer.h>

#include <Ticker.h>
#define pinLedWifi D4
Ticker ticker;

void parpadearTicker(){
  byte estado = digitalRead(pinLedWifi);
  digitalWrite(pinLedWifi, !estado);
}

void conectarWifi(){
   Serial.begin(115200);

  pinMode(pinLedWifi, OUTPUT);
  ticker.attach(0.2, parpadearTicker);
  
  WiFiManager wifiManager;

  //wifiManager.resetSettings();

  if(!wifiManager.autoConnect("EJC_ESP8266")){
    Serial.println("Fallo en la conexion");
    ESP.reset();
    delay(1000);
  }

  Serial.println("Ya estas conectado");

  ticker.detach();
  digitalWrite(pinLedWifi, HIGH);
}

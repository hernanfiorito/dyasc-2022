#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <RedWifi.cpp>
#include <ConsultorServidorTravis.cpp>
#include <Baliza.cpp>

void setup() {
  Serial.begin(115200);

  RedWifi red("CAPPONI", "clau1963");
  red.conectar();

}

void loop() {
  
  ConsultorServidorTravis consultor;
  Baliza baliza;
  JSONVar ultimoBuild = consultor.obtenerBuild();

}
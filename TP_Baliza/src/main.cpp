#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <RedWifi.cpp>
#include <ConsultorServidorTravis.cpp>
#include <Baliza.cpp>

Baliza baliza;

void setup() {
  Serial.begin(115200);

  //RedWifi red("CAPPONI", "clau1963");
  //red.conectar();

}

void loop() {

  baliza.encenderLed(13);
  delay(1000);
  baliza.apagarLed(13);
  delay(1000);

  //ConsultorServidorTravis consultor;
  //JSONVar ultimoBuild = consultor.obtenerBuild();

}
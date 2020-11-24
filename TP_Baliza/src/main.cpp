#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <RedWifi.h>
#include <Baliza.h>

Baliza* baliza = new Baliza;
ConsultorServidor* consultor = new ConsultorServidorTravis("https://api.travis-ci.org/repos/capponi/dyasc-2020/builds");
RedWifi* red = new RedWifi("CAPPONI", "clau1963");

void setup() {
  Serial.begin(115200);  
  red->conectar();
}

void loop() {  
  baliza->ejecutar(consultor, red->chequearConexion());
}
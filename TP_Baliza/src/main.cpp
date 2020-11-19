#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <RedWifi.cpp>
#include <Baliza.cpp>
#include <ConsultorServidorTravis.cpp>

Baliza baliza;
ConsultorServidorTravis consultor;
String ultimoEstado;
String estadoActual;

void setup() {
  Serial.begin(115200);
  
  RedWifi red("CAPPONI", "clau1963");
  red.conectar();
 
  ultimoEstado = consultor.obtenerEstado();
}

void loop() {
  delay(4000);
  estadoActual =consultor.obtenerEstado();
  
  if(estadoActual.compareTo("Exitoso")==0){
    baliza.encenderLed(25);
  } else if(estadoActual.compareTo("Fallido")==0){
    baliza.encenderLed(13);
  } else if(estadoActual.compareTo("En progreso")==0){
    baliza.parpadearVerdeYRojo();
  }

  

}
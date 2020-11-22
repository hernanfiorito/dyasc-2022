#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <RedWifi.h>
#include <Baliza.h>
#include <ConsultorServidorTravis.h>

Baliza* baliza = new Baliza;
ConsultorServidorTravis* consultor = new ConsultorServidorTravis;
String ultimoEstado;
String estadoActual;

void setup() {
  Serial.begin(115200);
  
  RedWifi red("Hernan95", "perroloco");
  red.conectar();
 
  ultimoEstado = consultor->obtenerEstado();
}

void loop() {
  estadoActual = consultor->obtenerEstado();
  Serial.println(estadoActual.equals("Exitoso")==0);
  if(estadoActual.equals("Exitoso")==0){
    baliza->encenderLed(25);
  } else if(estadoActual.equals("Fallido")==0){
    baliza->encenderLed(13);
  } else if(estadoActual.equals("En progreso")==0){
    baliza->parpadearVerdeYRojo();
  }
  delay(200);
}
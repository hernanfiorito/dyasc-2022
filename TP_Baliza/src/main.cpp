#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include <RedWifi.h>
#include <Baliza.h>
#include <ConsultorServidor.h>

Baliza* baliza = new Baliza;
ConsultorServidorTravis* consultor = new ConsultorServidorTravis("https://api.travis-ci.org/repos/hernanfiorito/dyasc-2020/builds");
RedWifi* red = new RedWifi("Hernan95", "perroloco");
String ultimoEstado;
String estadoActual;
int fueReconectado = 0;

void setup() {
  Serial.begin(115200);
  
  red->conectar();
 
  ultimoEstado = consultor->obtenerEstado();
}

void loop() {
  if(!red->chequearConexion()){
    baliza->apagarLed(13);
    baliza->apagarLed(25);
    while(!red->chequearConexion()){
      baliza->encenderLed(27);
    }
    baliza->apagarLed(27);
    fueReconectado = 1;
  }

  estadoActual = consultor->obtenerEstado();

  if(estadoActual.equals("Exitoso")==0){
    baliza->apagarLed(13);
    if(estadoActual != ultimoEstado || fueReconectado){
      baliza->parpadearLed(25);
    }
    baliza->encenderLed(25);
  } else if(estadoActual.equals("Fallido")==0){
    baliza->apagarLed(25);
    if(estadoActual != ultimoEstado || fueReconectado){
      baliza->parpadearLed(13);
    }
    baliza->encenderLed(13);
  } else if(estadoActual.equals("En progreso")==0){
    baliza->parpadearVerdeYRojo();
  }
  fueReconectado = 0;
  delay(200);
}
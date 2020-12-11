#include <Arduino.h>
#include <Arduino_JSON.h>
#include "Baliza.h"

Baliza::Baliza(){
    desconectado=0;
    ultimoEstado="";
    led_rojo = 13;
    led_amarillo = 27;
    led_verde = 25;

    pinMode(led_rojo, OUTPUT);
    pinMode(led_amarillo, OUTPUT);
    pinMode(led_verde, OUTPUT);

    
}

void Baliza::encenderLed(int led){
    digitalWrite(led, HIGH);
}


void Baliza::apagarLed(int led){
    digitalWrite(led, LOW);
}

void Baliza::parpadearLed(int led){
    for(int i = 0; i < 3; i++){
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
        delay(300);
    }
}

void Baliza::parpadearVerdeYRojo(){
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_rojo, HIGH);
    delay(300);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rojo, LOW);    

}

void Baliza::encenderExitoso(){
    apagarLed(led_rojo);
    if((ultimoEstado.equals("Fallido") == 1) || desconectado){
        desconectado=0;
        parpadearLed(led_verde);
    }
    encenderLed(led_verde);
    

}
void Baliza::encenderFallido(){
    apagarLed(led_verde);
    if((ultimoEstado.equals("Exitoso") == 1)  || desconectado){
        desconectado=0;
        parpadearLed(led_rojo);
    }
    encenderLed(led_rojo);
    
    
}

void Baliza::encenderSegunEstado(){
    if(estadoActual.equals("Exitoso")==1){
        encenderExitoso();              
    } else if(estadoActual.equals("Fallido")==1){
        encenderFallido();        
    } else if(estadoActual.equals("En progreso")==1){
        parpadearVerdeYRojo();
    }

}

void Baliza::ejecutar(ConsultorServidor* consultor, int estaConectado){
    if(estaConectado){   
        if(ultimoEstado.equals("")==1){
            ultimoEstado = consultor->obtenerEstado();
        } else if(estadoActual.equals("En progreso") == 0){
            ultimoEstado = estadoActual;
        }
        apagarLed(led_amarillo);
        estadoActual = consultor->obtenerEstado();   
        encenderSegunEstado(); 
        
    } else {
        apagarLed(led_rojo);
        apagarLed(led_verde);
        encenderLed(led_amarillo);
        desconectado=1;
    }

}
#include <Arduino.h>
#include <Arduino_JSON.h>

class Baliza
{
    public:
        Baliza();
        void encenderLed(int led);
        void apagarLed(int led);
        void parpadearLed(int led);
        void parpadearVerdeYRojo();

    private:
        int led_rojo;
        int led_amarillo;
        int led_verde;
};

Baliza::Baliza(){
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
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    delay(300);
}

void Baliza::parpadearVerdeYRojo(){
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_rojo, HIGH);
    delay(300);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_rojo, LOW);
    delay(300);
}
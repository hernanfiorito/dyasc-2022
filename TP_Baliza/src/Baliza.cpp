#include <Arduino.h>
#include <Arduino_JSON.h>

class Baliza
{
    public:
    Baliza(){
        led_rojo = 13;
        led_amarillo = 27;
        led_verde = 25;

        pinMode(led_rojo, OUTPUT);
        pinMode(led_amarillo, OUTPUT);
        pinMode(led_verde, OUTPUT);

    }

    void encenderLed(int led){
        digitalWrite(led, HIGH);
    }

    void encenderAmarillo(){
        digitalWrite(led_amarillo, HIGH);
    }

    void apagarLed(int led){
        digitalWrite(led, LOW);
    }

    void parpadearLed(int led){
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
        delay(300);
    }

    void parpadearVerdeYRojo(){
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_rojo, HIGH);
        delay(300);
        digitalWrite(led_verde, LOW);
        digitalWrite(led_rojo, LOW);
        delay(300);

    }

    private:
        int led_rojo;
        int led_amarillo;
        int led_verde;
};


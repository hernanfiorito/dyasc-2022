#include <ConsultorServidor.h>

class Baliza
{
    public:
        Baliza();
        void encenderLed(int led);
        void apagarLed(int led);
        void parpadearLed(int led);
        void parpadearVerdeYRojo();
        void ejecutar(ConsultorServidor* consultor, int estaConectado);
        

    private:
        int led_rojo;
        int led_amarillo;
        int led_verde;
        int desconectado;
        String ultimoEstado;
        String estadoActual;
        void encenderSegunEstado();
        void encenderExitoso();
        void encenderFallido();
       

};
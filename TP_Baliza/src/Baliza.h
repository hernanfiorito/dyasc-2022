class Baliza
{
    public:
        Baliza();
        void encenderLed(int led);
        void encenderAmarillo();
        void apagarLed(int led);
        void parpadearLed(int led);
        void parpadearVerdeYRojo();

    private:
        int led_rojo;
        int led_amarillo;
        int led_verde;
};
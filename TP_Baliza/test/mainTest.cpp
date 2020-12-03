#include <Arduino.h>
#include <unity.h>
#include <RedWifi.h>
#include <Baliza.h>
RedWifi* redTest = new RedWifi("Hernan95", "perroloco");
Baliza* balizaTest = new Baliza;
int ledVerde = 25;
int ledRojo = 13;
int ledAmarillo = 27;
ConsultorServidor* consultorFallido = new ConsultorServidorFallidoMock;
ConsultorServidor* consultorExitoso = new ConsultorServidorExitosoMock;


void wifi_conectado_correctamente(void){
    redTest->conectar();
    TEST_ASSERT_EQUAL(1, redTest->chequearConexion());
}

void led_verde_apagado(void){
    balizaTest->apagarLed(ledVerde);
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledVerde));
}

void led_verde_encendido(void){
    balizaTest->encenderLed(ledVerde);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(ledVerde));
}

void led_rojo_apagado(void){
    balizaTest->apagarLed(ledRojo);
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledRojo));
}

void led_rojo_encendido(void){
    balizaTest->encenderLed(ledRojo);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(ledRojo));
}

void cuando_estado_fallido_enciende_led_rojo(void){
    balizaTest->ejecutar(consultorFallido, 1);    
    TEST_ASSERT_EQUAL(HIGH, digitalRead(ledRojo));
}

void cuando_estado_fallido_apaga_led_verde_y_amarillo(void){
    balizaTest->ejecutar(consultorFallido, 1);    
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledVerde));
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledAmarillo));
}

void cuando_estado_exitoso_enciende_led_verde(void){
    balizaTest->ejecutar(consultorExitoso, 1);    
    TEST_ASSERT_EQUAL(HIGH, digitalRead(ledVerde));
}

void cuando_estado_exitoso_apaga_led_rojo_y_amarillo(void){
    balizaTest->ejecutar(consultorExitoso, 1);    
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledRojo));
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledAmarillo));
}

void cuando_esta_desconectado_enciende_led_amarillo(void){
    balizaTest->ejecutar(consultorExitoso, 0);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(ledAmarillo));
}

void cuando_esta_desconectado_apaga_led_verde_y_rojo(void){
    balizaTest->ejecutar(consultorExitoso, 0);
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledVerde));
    TEST_ASSERT_EQUAL(LOW, digitalRead(ledRojo));
}

void setup()
{
    delay(2000); // service delay
    UNITY_BEGIN();

    RUN_TEST(wifi_conectado_correctamente);
    RUN_TEST(led_verde_apagado);
    RUN_TEST(led_verde_encendido);
    RUN_TEST(led_rojo_apagado);
    RUN_TEST(led_rojo_encendido);
    RUN_TEST(cuando_estado_fallido_enciende_led_rojo);
    RUN_TEST(cuando_estado_fallido_apaga_led_verde_y_amarillo);
    RUN_TEST(cuando_estado_exitoso_enciende_led_verde);
    RUN_TEST(cuando_estado_exitoso_apaga_led_rojo_y_amarillo);
    RUN_TEST(cuando_esta_desconectado_enciende_led_amarillo);
    RUN_TEST(cuando_esta_desconectado_apaga_led_verde_y_rojo);

    UNITY_END(); // stop unit testing
}

void loop()
{
}
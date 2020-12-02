#include <unity.h>
#include <Baliza.h>
#include <RedWifi.h>

Baliza* balizaTest = new Baliza();
ConsultorServidor* consultorNormal = new ConsultorServidorTravis("https://api.travis-ci.org/repos/capponi/dyasc-2020/builds");
ConsultorServidor* mockExitoso = new MockConsultorServidorExitoso("https://api.travis-ci.org/repos/capponi/dyasc-2020/builds");
ConsultorServidor* mockFallido = new MockConsultorServidorFallido("https://api.travis-ci.org/repos/capponi/dyasc-2020/builds");
RedWifi* redTest = new RedWifi("Hernan95", "perroloco");
RedWifi* redDesconectada = new MockRedWifiDesconectada("Hernan95", "perroloco");

void chequearEncendidoDeLedVerdeConBuildExitoso(){
    balizaTest->ejecutar(mockExitoso, redTest->chequearConexion());
    TEST_ASSERT_EQUAL(HIGH, digitalRead(25));
    TEST_ASSERT_EQUAL(LOW, digitalRead(13));
    TEST_ASSERT_EQUAL(LOW, digitalRead(27));
}

void chequearEncendidoDeLedRojoConBuildFallido(){
    balizaTest->ejecutar(mockFallido, redTest->chequearConexion());
    TEST_ASSERT_EQUAL(LOW, digitalRead(25));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(13));
    TEST_ASSERT_EQUAL(LOW, digitalRead(27));
}

void chequearEncendidoDeLedAmarilloConWiFiDesconectado(){
    balizaTest->ejecutar(consultorNormal, redDesconectada->chequearConexion());
    TEST_ASSERT_EQUAL(LOW, digitalRead(25));
    TEST_ASSERT_EQUAL(LOW, digitalRead(13));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(27));
}
void setup(){
    delay(2000);
    redTest->conectar();
    UNITY_BEGIN();
}

void loop(){
    RUN_TEST(chequearEncendidoDeLedVerdeConBuildExitoso);
    RUN_TEST(chequearEncendidoDeLedRojoConBuildFallido);
    RUN_TEST(chequearEncendidoDeLedAmarilloConWiFiDesconectado);
    delay(1000);
    UNITY_END();
}
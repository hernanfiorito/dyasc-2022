#include <unity.h>
#include <Baliza.h>
#include <RedWifi.h>

Baliza* balizaTest = new Baliza;
ConsultorServidor* mockExitoso = new MockConsultorServidorExitoso("https://api.travis-ci.org/repos/capponi/dyasc-2020/builds");
RedWifi* redTest = new RedWifi("Hernan95", "perroloco");


void siempreBien(){
    TEST_ASSERT_EQUAL(true, true);
}

void chequearEncendidoDeLedVerdeConBuildExitoso(){
    balizaTest->ejecutar(mockExitoso, redTest->chequearConexion());
    TEST_ASSERT_EQUAL(HIGH, digitalRead(25));
}
void setup(){
    delay(2000);
    redTest->conectar();
    UNITY_BEGIN();
}

void loop(){
    RUN_TEST(siempreBien);
    RUN_TEST(chequearEncendidoDeLedVerdeConBuildExitoso);
    UNITY_END();
}

/*int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(siempreBien);

    UNITY_END();

    return 0;
}*/
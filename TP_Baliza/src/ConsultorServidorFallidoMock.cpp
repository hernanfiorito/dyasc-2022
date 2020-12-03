#include <Arduino.h>
#include "ConsultorServidor.h"

ConsultorServidorFallidoMock::ConsultorServidorFallidoMock():ConsultorServidor(""){}

String ConsultorServidorFallidoMock::obtenerEstado(){
    return "Fallido";
}

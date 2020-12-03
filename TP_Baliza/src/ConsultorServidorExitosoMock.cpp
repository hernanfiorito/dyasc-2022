#include <Arduino.h>
#include "ConsultorServidor.h"

ConsultorServidorExitosoMock::ConsultorServidorExitosoMock():ConsultorServidor(""){}

String ConsultorServidorExitosoMock::obtenerEstado(){
    return "Exitoso";
}

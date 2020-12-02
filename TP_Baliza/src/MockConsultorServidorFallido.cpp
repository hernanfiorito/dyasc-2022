#include "ConsultorServidor.h"

MockConsultorServidorFallido::MockConsultorServidorFallido(String url) : ConsultorServidor(url){}

JSONVar MockConsultorServidorFallido::obtenerBuild(){
    return new JSONVar();
}

String MockConsultorServidorFallido::obtenerEstado(){
    return "Fallido";
}

String MockConsultorServidorFallido::obtenerURL(){
    return ConsultorServidor::obtenerURL();
}
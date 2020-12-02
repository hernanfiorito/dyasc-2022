#include "ConsultorServidor.h"

MockConsultorServidorExitoso::MockConsultorServidorExitoso(String url) : ConsultorServidor(url){}

JSONVar MockConsultorServidorExitoso::obtenerBuild(){
    return new JSONVar();
}

String MockConsultorServidorExitoso::obtenerEstado(){
    return "Exitoso";
}

String MockConsultorServidorExitoso::obtenerURL(){
    return ConsultorServidor::obtenerURL();
}
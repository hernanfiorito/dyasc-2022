#include <ConsultorServidor.h>

ConsultorServidor::ConsultorServidor(String url){
    _url = url;
}

String ConsultorServidor::obtenerURL(){
    return _url;
}
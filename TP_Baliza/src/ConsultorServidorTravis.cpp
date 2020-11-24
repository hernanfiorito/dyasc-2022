#include <Arduino.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "ConsultorServidor.h"

ConsultorServidorTravis::ConsultorServidorTravis(String url) : ConsultorServidor(url){}

String ConsultorServidorTravis::obtenerURL(){
    return ConsultorServidor::obtenerURL();
}

JSONVar ConsultorServidorTravis::obtenerBuild(){
    HTTPClient http; 
    http.begin(obtenerURL());

    int httpCode = http.GET();   
    String payload = http.getString();

    JSONVar myObject = JSON.parse(payload);
    JSONVar* build = &myObject;

    http.end();

    return build[0];
}

String ConsultorServidorTravis::obtenerEstado(){
    JSONVar build = obtenerBuild();
    String estadoBuild = JSON.stringify(build[0]["state"]);
    int resultadoBuild = build[0]["result"];
    if(estadoBuild.equals("started") == 0 || estadoBuild.equals("created") == 0){
        return "En progreso";
    } else if(estadoBuild.equals("finished") == 0 && resultadoBuild == 0){
        return "Exitoso";
    } else{            
        return "Fallido";
    }
    
}
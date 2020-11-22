#include <Arduino.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "ConsultorServidorTravis.h"

ConsultorServidorTravis::ConsultorServidorTravis(){
    //https://api.travis-ci.org/repos/capponi/dyasc-2020/builds
    _url = "https://api.travis-ci.org/repos/hernanfiorito/dyasc-2020/builds";
}

JSONVar ConsultorServidorTravis::obtenerBuild(){
    HTTPClient http; 
    http.begin(_url);

    int httpCode = http.GET();   
    String payload = http.getString();

    JSONVar myObject = JSON.parse(payload);
    JSONVar* build = &myObject;
    
    //Serial.println(build);

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
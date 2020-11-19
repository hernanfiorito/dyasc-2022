#include <Arduino.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

class ConsultorServidorTravis
{
    public:
    ConsultorServidorTravis(){
        _url = "https://api.travis-ci.org/repos/capponi/dyasc-2020/builds";
    }

    JSONVar obtenerBuild(){
        HTTPClient http; 
        http.begin(_url);

        int httpCode = http.GET();   
        String payload = http.getString();
    
        JSONVar myObject = JSON.parse(payload);
        JSONVar build = myObject[0];

        http.end();

        return build;
    }

    String obtenerEstado(){
        JSONVar build = obtenerBuild();
        if(strcmp(build["state"], "started")==0 || strcmp(build["state"], "created")==0){
            return "En progreso";
        } else if(strcmp(build["state"], "finished")==0 && strcmp(build["state"], "0")==0){
            return "Exitoso";
        } else{            
            return "Fallido";
        }
        
    }

    private:
        String _url;

};
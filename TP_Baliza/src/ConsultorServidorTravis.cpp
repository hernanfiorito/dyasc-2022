#include <HTTPClient.h>
#include <Arduino_JSON.h>

class ConsultorServidorTravis
{
    public:
        ConsultorServidorTravis();
        JSONVar obtenerBuild();

    private:
        String _url;

};

ConsultorServidorTravis::ConsultorServidorTravis(){
        _url = "https://api.travis-ci.org/repos/capponi/dyasc-2020/builds";
}

JSONVar ConsultorServidorTravis::obtenerBuild(){
        HTTPClient http; 
        http.begin(_url);

        int httpCode = http.GET();        
        String payload = http.getString();
    
        JSONVar myObject = JSON.parse(payload);
        JSONVar build = myObject[0];

        http.end();

        return build;
}
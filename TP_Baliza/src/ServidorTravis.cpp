#include <HTTPClient.h>
#include <Arduino_JSON.h>

class ServidorTravis
{
    public:
    ServidorTravis(){
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

    private:
        String _url;

};
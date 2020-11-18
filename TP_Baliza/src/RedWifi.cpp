#include <WiFi.h>

class RedWifi
{
    public:
    RedWifi(const char* ssid, const char* password){
        _ssid = ssid;
        _password = password;

    }

    void conectar(){
        WiFi.begin(_ssid, _password);

        while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        }
        
        Serial.println("WiFi connected.");
    }

    private:
    const char* _ssid;
    const char* _password;
};
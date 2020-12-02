#include <RedWifi.h>

MockRedWifiDesconectada::MockRedWifiDesconectada(const char* ssid, const char* password) : RedWifi(ssid, password){}

int MockRedWifiDesconectada::chequearConexion(){
    return 0;
}
class RedWifi
{
    public:
    RedWifi(const char* ssid, const char* password);
    void conectar();
    virtual int chequearConexion();

    private:
    const char* _ssid;
    const char* _password;
};

class MockRedWifiDesconectada : public RedWifi
{
    public:
        MockRedWifiDesconectada(const char* ssid, const char* password);
        int chequearConexion();
};
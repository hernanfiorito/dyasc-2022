class RedWifi
{
    public:
    RedWifi(const char* ssid, const char* password);
    void conectar();
    int chequearConexion();

    private:
    const char* _ssid;
    const char* _password;
};
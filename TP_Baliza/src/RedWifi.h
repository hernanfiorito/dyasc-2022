class RedWifi
{
    public:
    RedWifi(const char* ssid, const char* password);
    void conectar();

    private:
    const char* _ssid;
    const char* _password;
};
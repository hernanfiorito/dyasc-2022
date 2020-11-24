#include <Arduino_JSON.h>

class ConsultorServidor
{
    public:
        ConsultorServidor(String url);
        virtual JSONVar obtenerBuild() = 0;
        virtual String obtenerEstado() = 0;
        virtual String obtenerURL();

    private:
        String _url;
};

class ConsultorServidorTravis : public ConsultorServidor
{
    public:
        ConsultorServidorTravis(String url);
        JSONVar obtenerBuild();
        String obtenerEstado();
        String obtenerURL();

};
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

class MockConsultorServidorExitoso : public ConsultorServidor
{
    public:
        MockConsultorServidorExitoso(String url);
        JSONVar obtenerBuild();
        String obtenerEstado();
        String obtenerURL();
};

class MockConsultorServidorFallido : public ConsultorServidor
{
    public:
        MockConsultorServidorFallido(String url);
        JSONVar obtenerBuild();
        String obtenerEstado();
        String obtenerURL();
};
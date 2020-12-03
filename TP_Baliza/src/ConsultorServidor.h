#include <Arduino_JSON.h>

class ConsultorServidor
{
    public:
        ConsultorServidor(String url);        
        virtual String obtenerEstado() = 0;      

    protected:
        String _url;
};

class ConsultorServidorTravis : public ConsultorServidor
{
    public:
        ConsultorServidorTravis(String url);        
        String obtenerEstado();
        JSONVar obtenerBuild();


};

class ConsultorServidorFallidoMock : public ConsultorServidor
{
    public:
        ConsultorServidorFallidoMock();        
        String obtenerEstado();        

};

class ConsultorServidorExitosoMock : public ConsultorServidor
{
    public:
        ConsultorServidorExitosoMock();        
        String obtenerEstado();        

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
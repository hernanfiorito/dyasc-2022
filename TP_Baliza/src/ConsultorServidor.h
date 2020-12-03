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
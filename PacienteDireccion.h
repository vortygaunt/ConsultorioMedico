#pragma once
#include <cstring>

using namespace std;

class PacienteDireccion{
private:
    char _calle[30];
    int _numero;
    char _localidad[20];

public:

    PacienteDireccion();

    void setCalle(const char*calle);
    void setNumero(int numero);
    void setLocalidad(const char* localidad);

    const char* getCalle() const;
    int getNumero() const;
    const char* getLocalidad() const;

    void cargar();
    void mostrar()const;

};


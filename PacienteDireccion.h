#pragma once
#include <cstring>



class PacienteDireccion{
private:
    char _calle[30];
    int _numero;
    char _localidad[20];

public:

    PacienteDireccion();

    void setCalle(const std::string &calle);
    void setNumero(int numero);
    void setLocalidad(const std::string &localidad);

    std::string getCalle();
    int getNumero();
    std::string getLocalidad();

    void cargar();
    void mostrar();

};



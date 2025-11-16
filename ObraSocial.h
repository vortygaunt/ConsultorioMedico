#pragma once
#include <string>

class ObraSocial{
public:
    ObraSocial();
    ObraSocial(int idObraSocial, std::string nombre, std::string telefonoObraSocial, bool estado = true);

    void setIdObraSocial(int idObraSocial);
    void setNombre(std::string nombre);
    void setTelefonoObraSocial(std::string telefonoObraSocial);
    void setEstado(bool estado);

    int getIdObraSocial();
    std::string getNombre();
    std::string getTelefonoObraSocial();
    bool getEstado();

    void mostrar();
private:
    int _idObraSocial;
    char _nombre[30];
    char _telefonoObraSocial[20];
    bool _estado;
};

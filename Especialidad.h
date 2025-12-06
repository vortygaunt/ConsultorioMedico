#pragma once
#include <string>

class Especialidad{
public:
    Especialidad();
    Especialidad(int codigoEspecialidad, std::string descripcion, bool estado);

    void setCodigoEspecialidad(int codigoEspecialidad);
    void setDescripcion(std::string descripcion);
    void setEstado(bool estado);

    int getCodigoEspecialidad();
    std::string getDescripcion();
    bool getEstado();

    void mostrar();

private:
    int _codigoEspecialidad;
    char _descripcion[50];
    bool _estado;
};

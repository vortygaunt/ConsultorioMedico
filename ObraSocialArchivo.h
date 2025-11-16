#pragma once
#include <string>
#include "ObraSocial.h"

class ObraSocialArchivo{
public:
    ObraSocialArchivo(std::string nombreArchivo = "ObrasSociales.dat");

    bool guardar(ObraSocial registro);
    ObraSocial leer(int pos);
    bool modificar(int pos, ObraSocial &registro);
    bool eliminar(int pos);
    int getCantidadRegistro();
    int getnuevoID();
private:
    std::string _nombreArchivo;
};

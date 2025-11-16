#pragma once
#include <string>
#include "Consultorio.h"

class ConsultorioArchivo{
public:
    ConsultorioArchivo(std::string nombreArchivo = "consultorios.dat");

    bool guardar(Consultorio registro);
    Consultorio leer(int pos);
    bool modificar(int pos, Consultorio &registro);
    bool eliminar(int pos);
    int getCantidadRegistro();

private:
    std::string _nombreArchivo;
};

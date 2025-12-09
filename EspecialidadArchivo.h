#pragma once
#include <string>
#include "Especialidad.h"

class EspecialidadArchivo{
public:
    EspecialidadArchivo(std::string nombreArchivo = "especialidades.dat");

    bool guardar(Especialidad registro);
    Especialidad leer(int pos);
    bool modificar(int pos, Especialidad &registro);
    bool eliminar(int pos);
    int getCantidadRegistro();
    int getNuevoCodigo();
    bool existeCodigo(int codigo);
    void vaciarArchivo();
    bool existe();

private:
    std::string _nombreArchivo;
};

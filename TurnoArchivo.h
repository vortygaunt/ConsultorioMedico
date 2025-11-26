#pragma once
#include <string>
#include "Turno.h"

class TurnoArchivo{
public:
    TurnoArchivo(std::string nombreArchivo = "turnos.dat");

    bool guardar(Turno registro);
    Turno leer(int pos);
    bool modificar(int pos, Turno &registro);
    bool eliminar(int pos);
    int getCantidadRegistro();
    int getNuevoID();
    void vaciarArchivo();
    bool existe();

private:
    std::string _nombreArchivo;
};

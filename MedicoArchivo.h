#pragma once
#include <string>
#include "Medico.h"

class MedicoArchivo{
public:
    MedicoArchivo(std::string nombreArchivo = "medicos.dat");

    bool guardar(Medico registro);
    Medico leer(int pos);
    bool modificar(int pos, Medico &registro);
    bool eliminar(int pos);
    int getCantidadRegistro();
    int getnuevoID();
    void vaciarArchivo();
    bool existe();


private:
    std::string _nombreArchivo;
};

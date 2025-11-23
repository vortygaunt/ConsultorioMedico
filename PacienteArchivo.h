#pragma once
#include <string>
#include <iostream>
#include "Paciente.h"

class PacienteArchivo {
private:
   std::string _nombreArchivo;

public:
    PacienteArchivo(std::string nombreArchivo = "pacientes.dat");

    bool guardar(Paciente registro);
    Paciente leer(int pos);
    bool modificar(int pos, Paciente& registro);
    bool eliminar(int pos);
    int getCantidadRegistro();

};

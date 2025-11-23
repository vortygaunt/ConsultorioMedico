#pragma once
#include "PacienteManager.h"

class PacienteMenuConsulta
{
private:
    int _opciones;
    PacienteManager _pacienteManager;

public:
    PacienteMenuConsulta();
    void mostrar();
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
};

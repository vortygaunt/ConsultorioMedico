#pragma once
#include "PacienteManager.h"

class PacienteMenuListar
{
private:
    int _opciones;
    PacienteManager _pacienteManager;

public:
    PacienteMenuListar();
    void mostrar();
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
};

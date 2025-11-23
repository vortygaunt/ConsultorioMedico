#pragma once
#include "PacienteManager.h"

class PacienteModificarMenu
{
private:
    int _opciones;
    PacienteManager _pacienteManager;

public:
    PacienteModificarMenu();
    void mostrar();
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
};

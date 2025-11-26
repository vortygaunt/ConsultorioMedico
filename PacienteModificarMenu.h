#pragma once
#include "Menu.h"
#include "PacienteManager.h"

class PacienteModificarMenu: public Menu{
private:
    PacienteManager _pacienteManager;

public:
    PacienteModificarMenu();
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
};

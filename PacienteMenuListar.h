#pragma once
#include "Menu.h"
#include "PacienteManager.h"

class PacienteMenuListar: public Menu{
private:
    PacienteManager _pacienteManager;

public:
    PacienteMenuListar();
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
};

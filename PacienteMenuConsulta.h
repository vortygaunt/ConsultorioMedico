#pragma once
#include "Menu.h"
#include "PacienteManager.h"

class PacienteMenuConsulta: public Menu{
private:
    PacienteManager _pacienteManager;

public:
    PacienteMenuConsulta();
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
};

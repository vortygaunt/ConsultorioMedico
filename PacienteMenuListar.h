#pragma once
#include "Menu.h"
#include "PacienteManager.h"

class PacienteMenuListar: public Menu{
private:

protected:
    PacienteManager _pacienteManager;

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

public:
    PacienteMenuListar();
};

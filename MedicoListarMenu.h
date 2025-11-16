#pragma once
#include "MedicoManager.h"

class MedicoListarMenu{
public:
    MedicoListarMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoManager _medicoManager;
private:
    int _cantidadOpciones;
};

#pragma once
#include "MedicoManager.h"

class MedicoConsultaMenu{
public:
    MedicoConsultaMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoManager _medicoManager;
private:
    int _cantidadOpciones;
};

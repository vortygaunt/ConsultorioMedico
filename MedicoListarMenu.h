#pragma once
#include "Menu.h"
#include "MedicoManager.h"

class MedicoListarMenu: public Menu{
public:
    MedicoListarMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoManager _medicoManager;
private:

};

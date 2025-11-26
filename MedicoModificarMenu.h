#pragma once
#include "Menu.h"
#include "MedicoManager.h"

class MedicoModificarMenu: public Menu{
public:
    MedicoModificarMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoManager _medicoManager;
private:

};

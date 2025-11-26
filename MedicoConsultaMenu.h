#pragma once
#include "Menu.h"
#include "MedicoManager.h"

class MedicoConsultaMenu: public Menu{
public:
    MedicoConsultaMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoManager _medicoManager;
private:

};

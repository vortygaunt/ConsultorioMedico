#pragma once
#include "Menu.h"
#include "MedicoManager.h"
#include "MedicoModificarMenu.h"
#include "MedicoConsultaMenu.h"
#include "MedicoListarMenu.h"

class MedicoMenu: public Menu{
public:
    MedicoMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoManager _medicoManager;
    MedicoModificarMenu _medicoModificarMenu;
    MedicoConsultaMenu _medicoConsultaMenu;
    MedicoListarMenu _medicoListarMenu;
private:

};

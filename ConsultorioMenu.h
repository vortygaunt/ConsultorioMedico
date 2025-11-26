#pragma once
#include "Menu.h"
#include "ConsultorioManager.h"
#include "ConsultorioListarMenu.h"

class ConsultorioMenu: public Menu{
public:
    ConsultorioMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ConsultorioManager _consultorioManager;
    ConsultorioListarMenu _consultorioListarMenu;
private:


};

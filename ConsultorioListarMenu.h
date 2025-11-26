#pragma once
#include "Menu.h"
#include "ConsultorioManager.h"

class ConsultorioListarMenu: public Menu{
public:
    ConsultorioListarMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ConsultorioManager _consultorioManager;
private:

};

#pragma once
#include "Menu.h"
#include "ObraSocialManager.h"
#include "ObraSocialModificarMenu.h"

class ObraSocialMenu: public Menu{
public:
    ObraSocialMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ObraSocialManager _obraSocialManager;
    ObraSocialModificarMenu _obraSocialModificarMenu;
private:

};

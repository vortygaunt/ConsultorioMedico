#pragma once
#include "Menu.h"
#include "ObraSocialManager.h"

class ObraSocialModificarMenu: public Menu{
public:
    ObraSocialModificarMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ObraSocialManager _obraSocialManager;
private:

};

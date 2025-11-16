#pragma once
#include "ObraSocialManager.h"
#include "ObraSocialModificarMenu.h"

class ObraSocialMenu{
public:
    ObraSocialMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ObraSocialManager _obraSocialManager;
    ObraSocialModificarMenu _obraSocialModificarMenu;
private:
    int _cantidadOpciones;
};

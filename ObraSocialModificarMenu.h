#pragma once
#include "ObraSocialManager.h"

class ObraSocialModificarMenu{
public:
    ObraSocialModificarMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ObraSocialManager _obraSocialManager;
private:
    int _cantidadOpciones;
};

#pragma once
#include "Menu.h"
#include "TurnoManager.h"

class TurnoModificarMenu: public Menu{
public:
    TurnoModificarMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    TurnoManager _turnoManager;
private:
};

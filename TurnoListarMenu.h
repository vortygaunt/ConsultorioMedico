#pragma once
#include "Menu.h"
#include "TurnoManager.h"

class TurnoListarMenu: public Menu{
public:
    TurnoListarMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    TurnoManager _turnoManager;
private:
};

#pragma once
#include "Menu.h"
#include "TurnoManager.h"

class TurnoConsultarMenu: public Menu{
public:
    TurnoConsultarMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    TurnoManager _turnoManager;
private:
};

#pragma once
#include "Menu.h"
#include "TurnoManager.h"
#include "TurnoModificarMenu.h"
#include "TurnoListarMenu.h"
#include "TurnoConsultarMenu.h"

class TurnoMenu: public Menu{
public:
    TurnoMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    TurnoManager _turnoManager;
    TurnoModificarMenu _turnoModificarMenu;
    TurnoListarMenu _turnoListarMenu;
    TurnoConsultarMenu _turnoConsultarMenu;
};

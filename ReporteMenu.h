#pragma once
#include "Menu.h"
#include "ReporteManager.h"

class ReporteMenu: public Menu{
public:
    ReporteMenu();


protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ReporteManager _reporteManager;
private:

};

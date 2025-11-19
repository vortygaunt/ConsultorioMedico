#pragma once
#include "ReporteManager.h"

class ReporteMenu{
public:
    ReporteMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ReporteManager _reporteManager;
private:
    int _cantidadOpciones;
};

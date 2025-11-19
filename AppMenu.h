#pragma once
#include "MedicoMenu.h"
#include "ConsultorioMenu.h"
#include "ObraSocialMenu.h"
#include "ReporteMenu.h"
#include "ConfiguracionMenu.h"

class AppMenu{
public:
    AppMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoMenu _medicoMenu;
    ConsultorioMenu _consultorioMenu;
    ObraSocialMenu _obraSocialMenu;
    ReporteMenu _reporteMenu;
    ConfiguracionMenu _configuracionMenu;
private:
    int _cantidadOpciones;
};

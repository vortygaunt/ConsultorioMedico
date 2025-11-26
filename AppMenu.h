#pragma once
#include "Menu.h"
#include "TurnoMenu.h"
#include "MedicoMenu.h"
#include "ConsultorioMenu.h"
#include "ObraSocialMenu.h"
#include "PacienteMenu.h"
#include "HistoriaClinicaMenu.h"
#include "EspecialidadMenu.h"
#include "ReporteMenu.h"
#include "ConfiguracionMenu.h"

class AppMenu: public Menu{
public:
    AppMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    TurnoMenu _turnoMenu;
    MedicoMenu _medicoMenu;
    ConsultorioMenu _consultorioMenu;
    ObraSocialMenu _obraSocialMenu;
    PacientesMenu _pacienteMenu;
    HistoriaClinicaMenu _historiaClinicaMenu;
    EspecialidadMenu _especialidadMenu;
    ReporteMenu _reporteMenu;
    ConfiguracionMenu _configuracionMenu;
private:

};

#pragma once
#include "Menu.h"
#include "HistoriaClinicaManager.h"
#include "HistoriaClinicaMenuModificar.h"
#include "HistoriaClinicaMenuConsulta.h"

class HistoriaClinicaMenu: public Menu{
private:

    HistoriaClinicaManager historiaManager;
    HistoriaClinicaMenuModificar modificarHC;
    HistoriaClinicaMenuConsulta consultaHC;

public:
    HistoriaClinicaMenu();

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
};

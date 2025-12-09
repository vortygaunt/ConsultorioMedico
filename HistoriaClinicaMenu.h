#pragma once
#include "Menu.h"
#include "HistoriaClinicaManager.h"
#include "HistoriaClinicaMenuModificar.h"
#include "HistoriaClinicaMenuConsulta.h"

class HistoriaClinicaMenu: public Menu{
private:

protected:
    HistoriaClinicaManager historiaManager;
    HistoriaClinicaMenuModificar modificarHC;
    HistoriaClinicaMenuConsulta consultaHC;

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

public:
    HistoriaClinicaMenu();
};

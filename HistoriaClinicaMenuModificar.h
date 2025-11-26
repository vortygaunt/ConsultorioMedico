#pragma once
#include "Menu.h"
#include "HistoriaClinicaManager.h"

class HistoriaClinicaMenuModificar: public Menu{
private:
    HistoriaClinicaManager historiaManager;

public:
    HistoriaClinicaMenuModificar();

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
};

#pragma once
#include "Menu.h"
#include "HistoriaClinicaManager.h"

class HistoriaClinicaMenuModificar: public Menu{
private:

protected:
    HistoriaClinicaManager historiaManager;

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
public:
    HistoriaClinicaMenuModificar();
};

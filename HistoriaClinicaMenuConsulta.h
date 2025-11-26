#pragma once
#include "Menu.h"
#include "HistoriaClinicaManager.h"

class HistoriaClinicaMenuConsulta: public Menu{
private:
    HistoriaClinicaManager historiaManager;

public:
    HistoriaClinicaMenuConsulta();

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
};

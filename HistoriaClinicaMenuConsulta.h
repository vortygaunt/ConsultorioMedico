#pragma once
#include "Menu.h"
#include "HistoriaClinicaManager.h"

class HistoriaClinicaMenuConsulta: public Menu{
private:

protected:
    HistoriaClinicaManager historiaManager;

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
public:
    HistoriaClinicaMenuConsulta();

};

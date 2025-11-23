#pragma once
#include "HistoriaClinicaManager.h"

class HistoriaClinicaMenuConsulta{
private:
    int _opciones;
    historiaClinicaManager historiaManager;

public:
    HistoriaClinicaMenuConsulta();
    void mostrar();
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
};

#pragma once
#include "HistoriaClinicaManager.h"

class HistoriaClinicaMenuModificar{
private:
    int _opciones;
    historiaClinicaManager historiaManager;

public:
    HistoriaClinicaMenuModificar();
    void mostrar();
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
};

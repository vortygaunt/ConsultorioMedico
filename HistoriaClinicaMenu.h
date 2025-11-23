#pragma once
#include "HistoriaClinicaManager.h"
#include "HistoriaClinicaMenuModificar.h"
#include "HistoriaClinicaMenuConsulta.h"

class HistoriaClinicaMenu
{
private:
    int _opciones;
    historiaClinicaManager historiaManager;
    HistoriaClinicaMenuModificar modificarHC;
    HistoriaClinicaMenuConsulta consultaHC;

public:
    HistoriaClinicaMenu();
    void mostrar();
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
};

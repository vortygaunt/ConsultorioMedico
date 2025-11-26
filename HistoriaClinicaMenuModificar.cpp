#include <iostream>
#include "HistoriaClinicaMenuModificar.h"

using namespace std;

HistoriaClinicaMenuModificar::HistoriaClinicaMenuModificar(){
    _cantidadOpciones = 3;
}


void HistoriaClinicaMenuModificar::mostrarOpciones(){
    cout << "============================="<<endl;
    cout << "  MODIFICAR HISTORIA CLINICA "<<endl;
    cout << "============================="<<endl;
    cout << "1. Modificar diagnostico"<<endl;
    cout << "2. Modificar observaciones"<<endl;
    cout << "3. Modificar tratamiento"<<endl;
    cout << "0. Volver al menu principal"<<endl;
    cout << "-----------------------------"<<endl;
}


void HistoriaClinicaMenuModificar::ejecutarOpciones(int opcion){
    switch(opcion){
    case 1:
       historiaManager.modificarDiagnostico();
        break;
    case 2:
       historiaManager.modificarObservaciones();
        break;
    case 3:
        historiaManager.modificarTratamiento();
        break;

    }
}

#include <iostream>
#include "HistoriaClinicaMenuConsulta.h"

using namespace std;

HistoriaClinicaMenuConsulta::HistoriaClinicaMenuConsulta(){
    _cantidadOpciones = 3;
}



void HistoriaClinicaMenuConsulta::mostrarOpciones(){
    cout << "============================="<<endl;
    cout << "           CONSULTAS          "<<endl;
    cout << "============================="<<endl;
    cout << "1. Por paciente"<<endl;
    cout << "2. Por fecha"<<endl;
    cout << "3. Por diagnostico"<<endl;
    cout << "0. Volver"<<endl;
    cout << "-----------------------------"<<endl;
}



void HistoriaClinicaMenuConsulta::ejecutarOpciones(int opcion){
    switch(opcion){
    case 1:
        historiaManager.consultarDniPaciente();
        break;
    case 2:
        historiaManager.consultarFechaHC();
        break;
    case 3:
       historiaManager.consultarDiagnostico();
        break;

    }
}

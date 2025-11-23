#include <iostream>
#include "HistoriaClinicaMenuConsulta.h"

using namespace std;

HistoriaClinicaMenuConsulta::HistoriaClinicaMenuConsulta(){
    _opciones = 4;
}

void HistoriaClinicaMenuConsulta::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
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

int HistoriaClinicaMenuConsulta::seleccionarOpciones(){
    int opcion;
    mostrarOpciones();
    cout<<"Opcion: ";
    cin>> opcion;

    while(opcion < 0 || opcion > _opciones){
      cout << "opcion incorrecta"<<endl;
      cout << "Opcion: ";
      cin >> opcion;
    }

    return opcion;
}

void HistoriaClinicaMenuConsulta::ejecutarOpcion(int opcion){
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

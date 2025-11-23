#include <iostream>
#include "HistoriaClinicaMenuModificar.h"

using namespace std;

HistoriaClinicaMenuModificar::HistoriaClinicaMenuModificar(){
    _opciones = 4;
}

void HistoriaClinicaMenuModificar::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
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

int HistoriaClinicaMenuModificar::seleccionarOpciones(){
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

void HistoriaClinicaMenuModificar::ejecutarOpcion(int opcion){
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

#include <iostream>
#include "HistoriaClinicaMenu.h"


using namespace std;

HistoriaClinicaMenu::HistoriaClinicaMenu(){
    _opciones = 5;
}

void HistoriaClinicaMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void HistoriaClinicaMenu::mostrarOpciones(){
    cout << "============================="<<endl;
    cout << "      MENU HISTORIAS CLINICAS     "<<endl;
    cout << "============================="<<endl;
    cout << "1. Cargar nueva Historia Clinica"<<endl;
    cout << "2. Modificar historia clinica"<<endl;
    cout << "3. Eliminar historia clinica"<<endl;
    cout << "4. Consultas"<<endl;
    cout << "0. Volver al menu anterior"<<endl;
    cout << "-----------------------------"<<endl;
}

int HistoriaClinicaMenu::seleccionarOpciones(){
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

void HistoriaClinicaMenu::ejecutarOpcion(int opcion){
    switch(opcion){
    case 1:
        historiaManager.cargar();
        break;
    case 2:
        modificarHC.mostrar();
        break;
    case 3:
        historiaManager.eliminarHistoriaClinica();
        break;
    case 4:
        consultaHC.mostrar();
        break;

    }
}

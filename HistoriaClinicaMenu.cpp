#include <iostream>
#include "HistoriaClinicaMenu.h"


using namespace std;

HistoriaClinicaMenu::HistoriaClinicaMenu(){
    _cantidadOpciones = 4;
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



void HistoriaClinicaMenu::ejecutarOpciones(int opcion){
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

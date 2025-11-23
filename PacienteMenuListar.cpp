#include <iostream>
#include "PacienteMenuListar.h"

using namespace std;

PacienteMenuListar::PacienteMenuListar(){
    _opciones = 4;
}

void PacienteMenuListar::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void PacienteMenuListar::mostrarOpciones(){
    cout << "============================="<<endl;
    cout << "           LISTADOS          "<<endl;
    cout << "============================="<<endl;
    cout << "1. Ordenados por apellido"<<endl;
    cout << "2. Ordenados por fecha de nacimiento"<<endl;
    cout << "3. Ordenados por Obra Social"<<endl;
    cout << "0. Volver"<<endl;
    cout << "-----------------------------"<<endl;
}

int PacienteMenuListar::seleccionarOpciones(){
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

void PacienteMenuListar::ejecutarOpcion(int opcion){
    switch(opcion){
    case 1:
        _pacienteManager.listarOrdenApellido();
        break;
    case 2:
         _pacienteManager.listarFechaNacimiento();
        break;
    case 3:
       _pacienteManager.listarObraSocial();
        break;

    }
}

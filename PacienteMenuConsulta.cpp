#include <iostream>
#include "PacienteMenuConsulta.h"

using namespace std;

PacienteMenuConsulta::PacienteMenuConsulta(){
    _opciones = 4;
}

void PacienteMenuConsulta::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void PacienteMenuConsulta::mostrarOpciones(){
    cout << "============================="<<endl;
    cout << "           CONSULTAS          "<<endl;
    cout << "============================="<<endl;
    cout << "1. Por DNI"<<endl;
    cout << "2. Por nombre y apellido"<<endl;
    cout << "3. Por Obra Social"<<endl;
    cout << "0. Volver"<<endl;
    cout << "-----------------------------"<<endl;
}

int PacienteMenuConsulta::seleccionarOpciones(){
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

void PacienteMenuConsulta::ejecutarOpcion(int opcion){
    switch(opcion){
    case 1:
        _pacienteManager.consultarDni();
        break;
    case 2:
        _pacienteManager.consultarApellidoNombre();
        break;
    case 3:
       _pacienteManager.consultarObraSocial();
        break;

    }
}

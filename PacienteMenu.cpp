#include <iostream>
#include "PacienteMenu.h"

using namespace std;

PacientesMenu::PacientesMenu(){
    _opciones = 6;
}

void PacientesMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpciones();
    system("cls");
    ejecutarOpcion(opcion);
    system("pause");
  }while(opcion != 0);
}

void PacientesMenu::mostrarOpciones(){
    cout << "============================="<<endl;
    cout << "      MENU DE PACIENTES      "<<endl;
    cout << "============================="<<endl;
    cout << "1. Agregar paciente"<<endl;
    cout << "2. Listar pacientes"<<endl;
    cout << "3. Modificar datos del paciente"<<endl;
    cout << "4. Consultas"<<endl;
    cout << "5. Dar de baja"<<endl;
    cout << "0. Volver al menu principal"<<endl;
    cout << "-----------------------------"<<endl;
}

int PacientesMenu::seleccionarOpciones(){
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

void PacientesMenu::ejecutarOpcion(int opcion){
    switch(opcion){
    case 1:
        _pacienteManager.cargar();
        break;
    case 2:
        _pacientesListar.mostrar();

        break;
    case 3:
        _pacienteModificar.mostrar();
        break;
    case 4:
        consultaPacientes.mostrar();
        break;
    case 5:
        _pacienteManager.eliminarPaciente();
        break;

    }
}

#include <iostream>
#include "PacienteMenu.h"

using namespace std;

PacientesMenu::PacientesMenu(){
    _cantidadOpciones = 5;
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


void PacientesMenu::ejecutarOpciones(int opcion){
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
        _consultaPacientes.mostrar();
        break;
    case 5:
        _pacienteManager.eliminarPaciente();
        break;

    }
}

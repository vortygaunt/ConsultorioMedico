#include <iostream>
#include "PacienteMenuConsulta.h"

using namespace std;

PacienteMenuConsulta::PacienteMenuConsulta(){
    _cantidadOpciones = 3;
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



void PacienteMenuConsulta::ejecutarOpciones(int opcion){
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

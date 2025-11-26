#include <iostream>
#include "PacienteMenuListar.h"

using namespace std;

PacienteMenuListar::PacienteMenuListar(){
    _cantidadOpciones = 4;
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


void PacienteMenuListar::ejecutarOpciones(int opcion){
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

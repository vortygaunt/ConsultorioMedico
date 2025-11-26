#include <iostream>
#include "PacienteModificarMenu.h"

using namespace std;

PacienteModificarMenu::PacienteModificarMenu(){
    _cantidadOpciones = 5;
}


void PacienteModificarMenu::mostrarOpciones(){
    cout << "============================="<<endl;
    cout << "       MODIFICAR DATOS       "<<endl;
    cout << "============================="<<endl;
    cout << "1. Modificar Telefono"<<endl;
    cout << "2. Modificar Direccion"<<endl;
    cout << "3. Modificar Email"<<endl;
    cout << "4. Modificar Obra Social"<<endl;
    cout << "0. Volver al menu principal"<<endl;
    cout << "-----------------------------"<<endl;
}


void PacienteModificarMenu::ejecutarOpciones(int opcion){
    switch(opcion){
    case 1:
        _pacienteManager.modificarTelefono();
        break;
    case 2:
        _pacienteManager.modificarDireccion();
        break;
    case 3:
        _pacienteManager.modificarEmail();
        break;
    case 4:
        _pacienteManager.modificarObraSocial();
        break;

    }
}

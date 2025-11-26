#include <iostream>
#include "TurnoConsultarMenu.h"

using namespace std;

    TurnoConsultarMenu::TurnoConsultarMenu(){
        _cantidadOpciones = 4;
    }

    void TurnoConsultarMenu::mostrarOpciones(){
        cout << "****** MENU CONSULTAR ******" << endl;
        cout << "1. CONSULTAR FECHA" << endl;
        cout << "2. CONSULTAR MEDICO" << endl;
        cout << "3. CONSULTAR PACIENTE" << endl;
        cout << "4. CONSULTAR ESTADO" << endl;
        cout << "****************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "****************************" << endl;
    }

    void TurnoConsultarMenu::ejecutarOpciones(int opcion){
            switch(opcion){
        case 1:
           _turnoManager.consultarFecha();
            break;
        case 2:
            _turnoManager.consultarMedico();
            break;
        case 3:
            _turnoManager.consultarPaciente();
            break;
        case 4:
            _turnoManager.consultarEstado();
            break;

            }
    }

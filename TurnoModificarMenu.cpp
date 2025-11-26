#include <iostream>
#include "TurnoModificarMenu.h"

using namespace std;

    TurnoModificarMenu::TurnoModificarMenu(){
        _cantidadOpciones = 4;
    }

    void TurnoModificarMenu::mostrarOpciones(){
        cout << "******** MENU MODIFICAR ********" << endl;
        cout << "1. MODIFICAR FECHA" << endl;
        cout << "2. MODIFICAR HORA" << endl;
        cout << "3. MODIFICAR NUMERO CONSULTORIO" << endl;
        cout << "4. MODIFICAR IMPORTE" << endl;
        cout << "********************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "********************************" << endl;
    }

    void TurnoModificarMenu::ejecutarOpciones(int opcion){
          switch(opcion){
    case 1:
       _turnoManager.modificarFecha();
        break;
    case 2:
        _turnoManager.modificarHora();
        break;
    case 3:
        _turnoManager.modificarNumeroConsultorio();
        break;
    case 4:
        _turnoManager.modificarImporte();
        break;

        }
    }

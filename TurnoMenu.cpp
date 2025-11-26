#include <iostream>
#include "TurnoMenu.h"

using namespace std;

    TurnoMenu::TurnoMenu(){
        _cantidadOpciones = 5;
    }

    void TurnoMenu::mostrarOpciones(){
        cout << "****** MENU TURNO ******" << endl;
        cout << "1. CARGAR TURNO" << endl;
        cout << "2. ELIMINAR TURNO" << endl;
        cout << "3. MODIFICAR TURNO" << endl;
        cout << "4. LISTADOS" << endl;
        cout << "5. CONSULTAS" << endl;
        cout << "*************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*************************" << endl;
    }
    void TurnoMenu::ejecutarOpciones(int opcion){
         switch(opcion){
    case 1:
       _turnoManager.cargar();
        break;
    case 2:
        _turnoManager.bajaLogica();
        break;
    case 3:
        _turnoModificarMenu.mostrar();
        break;
    case 4:
        _turnoListarMenu.mostrar();
        break;
    case 5:
         _turnoConsultarMenu.mostrar();
        break;

        }
    }

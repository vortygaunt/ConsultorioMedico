#include <iostream>
#include "MedicoMenu.h"
#include "funcionesGlobales.h"

using namespace std;

    MedicoMenu::MedicoMenu(){
        _cantidadOpciones = 5;
    }


    void MedicoMenu::mostrarOpciones(){
        cout << "****** MENU MEDICO ******" << endl;
        cout << "1. CARGAR MEDICO" << endl;
        cout << "2. ELIMINAR MEDICO" << endl;
        cout << "3. MODIFICAR DATOS" << endl;
        cout << "4. LISTADOS" << endl;
        cout << "5. CONSULTAS" << endl;
        cout << "*************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*************************" << endl;

    }


    void MedicoMenu::ejecutarOpciones(int opcion){
         switch(opcion){
    case 1:
       _medicoManager.cargar();
        break;
    case 2:
        _medicoManager.bajaLogica();
        break;
    case 3:
        _medicoModificarMenu.mostrar();
        break;
    case 4:
        _medicoListarMenu.mostrar();
        break;
    case 5:
         _medicoConsultaMenu.mostrar();
        break;

        }

    }

#include <iostream>
#include "MedicoModificarMenu.h"

using namespace std;

    MedicoModificarMenu::MedicoModificarMenu(){
        _cantidadOpciones = 3;
    }


    void MedicoModificarMenu::mostrarOpciones(){
        cout << "********** MENU MODIFICAR **********" << endl;
        cout << "1. MODIFICAR TELEFONO" << endl;
        cout << "2. MODIFICAR EMAIL" << endl;
        cout << "3. MODIFICAR CODIGO DE ESPECIALIDAD" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "************************************" << endl;
    }



    void MedicoModificarMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
       _medicoManager.modificarTelefono();
        break;
    case 2:
        _medicoManager.modificarEmail();
        break;
    case 3:
        _medicoManager.modificarCodigoEspecialidad();
        break;
        }
    }

#include <iostream>
#include "ObraSocialModificarMenu.h"

using namespace std;

    ObraSocialModificarMenu::ObraSocialModificarMenu(){
        _cantidadOpciones = 2;
    }


    void ObraSocialModificarMenu::mostrarOpciones(){
        cout << "********** MENU MODIFICAR **********" << endl;
        cout << "1. MODIFICAR NOMBRE" << endl;
        cout << "2. MODIFICAR TELEFONO" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "************************************" << endl;
    }


    void ObraSocialModificarMenu::ejecutarOpciones(int opcion){
         switch(opcion){
    case 1:
       _obraSocialManager.modificarNombre();
        break;
    case 2:
        _obraSocialManager.modificarTelefono();
        break;
        }
    }

#include <iostream>
#include "ObraSocialModificarMenu.h"

using namespace std;

    ObraSocialModificarMenu::ObraSocialModificarMenu(){
        _cantidadOpciones = 2;
    }

    void ObraSocialModificarMenu::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void ObraSocialModificarMenu::mostrarOpciones(){
        cout << "********** MENU MODIFICAR **********" << endl;
        cout << "1. MODIFICAR NOMBRE" << endl;
        cout << "2. MODIFICAR TELEFONO" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "************************************" << endl;
    }

    int ObraSocialModificarMenu::seleccionarOpciones(){
        int opcion;

        mostrarOpciones();

        cout << "Seleccionar opción: ";
        cin >> opcion;

        while(opcion < 0 || opcion > _cantidadOpciones){
            cout << "Opción incorrecta vuelva a elegir" << endl;
            cout << "Seleccionar opción: ";
            cin >> opcion;
        }

        return opcion;
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

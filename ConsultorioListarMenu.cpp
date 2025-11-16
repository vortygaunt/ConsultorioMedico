#include <iostream>
#include "ConsultorioListarMenu.h"

using namespace std;

    ConsultorioListarMenu::ConsultorioListarMenu(){
        _cantidadOpciones = 2;
    }

    void ConsultorioListarMenu::mostrar(){
           int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void ConsultorioListarMenu::mostrarOpciones(){
        cout << "********* LISTADOS *********" << endl;
        cout << "1. ORDENADOS POR NUMERO" << endl;
        cout << "2. ORDENADOS POR PISO" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*****************************" << endl;
    }

    int ConsultorioListarMenu::seleccionarOpciones(){
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

    void ConsultorioListarMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
       _consultorioManager.listadoOrdenNumero();
        break;
    case 2:
        _consultorioManager.listadoOrdenPiso();
        break;
        }
    }

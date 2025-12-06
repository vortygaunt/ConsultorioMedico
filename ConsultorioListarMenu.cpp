#include <iostream>
#include "ConsultorioListarMenu.h"

using namespace std;

    ConsultorioListarMenu::ConsultorioListarMenu(){
        _cantidadOpciones = 2;
    }



    void ConsultorioListarMenu::mostrarOpciones(){
        cout << "******** MENU LISTADO ********" << endl;
        cout << "1. ORDENADOS POR NUMERO" << endl;
        cout << "2. ORDENADOS POR PISO" << endl;
        cout << "******************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "******************************" << endl;
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

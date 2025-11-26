#include <iostream>
#include "ConsultorioMenu.h"

using namespace std;

    ConsultorioMenu::ConsultorioMenu(){
        _cantidadOpciones = 5;
    }



    void ConsultorioMenu::mostrarOpciones(){
        cout << "******* MENU CONSULTORIO *******" << endl;
        cout << "1. CARGAR CONSULTORIO" << endl;
        cout << "2. ELIMINAR CONSULTORIO" << endl;
        cout << "3. MODIFICAR CODIGO ESPECIALIDAD" << endl;
        cout << "4. LISTADOS" << endl;
        cout << "5. CONSULTAR" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "********************************" << endl;
    }



    void ConsultorioMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
       _consultorioManager.cargar();
        break;
    case 2:
        _consultorioManager.bajaLogica();
        break;
    case 3:
        _consultorioManager.modificarCodigoEspecialidad();
        break;
    case 4:
        _consultorioListarMenu.mostrar();
        break;
    case 5:
         _consultorioManager.consultarNumeroConsultorio();
        break;

        }
    }

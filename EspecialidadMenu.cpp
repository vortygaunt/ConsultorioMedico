#include <iostream>
#include "EspecialidadMenu.h"

using namespace std;

    EspecialidadMenu::EspecialidadMenu(){
        _cantidadOpciones = 5;
    }

    void EspecialidadMenu::mostrarOpciones(){
        cout << "*** MENU ESPECIALIDAD ***" << endl;
        cout << "1. CARGAR ESPECIALIDAD" << endl;
        cout << "2. ELIMINAR ESPECIALIDAD" << endl;
        cout << "3. MODIFICAR DESCRIPCION" << endl;
        cout << "4. LISTADO" << endl;
        cout << "5. CONSULTA" << endl;
        cout << "*************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*************************" << endl;
    }

    void EspecialidadMenu::ejecutarOpciones(int opcion){
          switch(opcion){
    case 1:
       _especialidadManager.cargar();
        break;
    case 2:
        _especialidadManager.bajaLogica();
        break;
    case 3:
        _especialidadManager.modificarDescripcion();
        break;
    case 4:
        _especialidadManager.listadoOrdenDescripcion();
        break;
    case 5:
         _especialidadManager.consultaDescripcion();
        break;

        }
    }

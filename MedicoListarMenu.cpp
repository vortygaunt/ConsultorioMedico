#include <iostream>
#include "MedicoListarMenu.h"

using namespace std;

    MedicoListarMenu::MedicoListarMenu(){
        _cantidadOpciones = 3;
    }



    void MedicoListarMenu::mostrarOpciones(){
        cout << "******** MENU LISTAR ********" << endl;
        cout << "1. ORDENADOS POR APELLIDO" << endl;
        cout << "2. ORDENADOS POR ESPECIALIDAD" << endl;
        cout << "3. ORDENADOS POR ANTIGÜEDAD" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*****************************" << endl;
    }



    void MedicoListarMenu::ejecutarOpciones(int opcion){
           switch(opcion){
    case 1:
       _medicoManager.listadoOrdenApellido();
        break;
    case 2:
        _medicoManager.listadoOrdenEspecialidad();
        break;
    case 3:
        _medicoManager.listadoOrdenAntiguedad();
        break;
        }
    }

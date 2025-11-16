#include <iostream>
#include "MedicoListarMenu.h"

using namespace std;

    MedicoListarMenu::MedicoListarMenu(){
        _cantidadOpciones = 3;
    }

    void MedicoListarMenu::mostrar(){
          int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void MedicoListarMenu::mostrarOpciones(){
        cout << "********* LISTADOS *********" << endl;
        cout << "1. ORDENADOS POR APELLIDO" << endl;
        cout << "2. ORDENADOS POR ESPECIALIDAD" << endl;
        cout << "3. ORDENADOS POR ANTIGÜEDAD" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*****************************" << endl;
    }

    int MedicoListarMenu::seleccionarOpciones(){
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

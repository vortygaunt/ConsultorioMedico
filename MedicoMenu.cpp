#include <iostream>
#include "MedicoMenu.h"

using namespace std;

    MedicoMenu::MedicoMenu(){
        _cantidadOpciones = 5;
    }

    void MedicoMenu::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);

    }

    void MedicoMenu::mostrarOpciones(){
        cout << "****** MENU MÉDICO ******" << endl;
        cout << "1. CARGAR MEDICO" << endl;
        cout << "2. ELIMINAR MEDICO" << endl;
        cout << "3. MODIFICAR DATOS" << endl;
        cout << "4. LISTADOS" << endl;
        cout << "5. CONSULTAS" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*************************" << endl;

    }

    int MedicoMenu::seleccionarOpciones(){
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

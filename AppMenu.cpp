#include <iostream>
#include "AppMenu.h"

using namespace std;

    AppMenu::AppMenu(){
        _cantidadOpciones = 9;
    }

    void AppMenu::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void AppMenu::mostrarOpciones(){
        cout << "**** MENU PRINCIPAL ****" << endl;
        cout << "1. MENU TURNO" << endl;
        cout << "2. MENU MEDICO" << endl;
        cout << "3. MENU PACIENTE" << endl;
        cout << "4. MENU CONSULTORIO" << endl;
        cout << "5. MENU OBRA SOCIAL" << endl;
        cout << "6. MENU HISTORIA CLINICA" << endl;
        cout << "7. MENU ESPECIALIDAD" << endl;
        cout << "8. MENU REPORTES" << endl;
        cout << "9. MENU CONFIGURACION" << endl;
        cout << "*************************" << endl;
        cout << "0 . SALIR DEL PROGRAMA" << endl;
        cout << "*************************" << endl;
    }

    int AppMenu::seleccionarOpciones(){
        int opcion;

        mostrarOpciones();

        cout << "Seleccionar opcion: ";
        cin >> opcion;

        while(opcion < 0 || opcion > _cantidadOpciones){
            cout << "Opción incorrecta vuelva a elegir" << endl;
            cout << "Seleccionar opcion: ";
            cin >> opcion;
        }

        return opcion;
    }

    void AppMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:

        break;
    case 2:
        _medicoMenu.mostrar();
        break;
    case 3:

        break;
    case 4:
        _consultorioMenu.mostrar();
        break;
    case 5:
         _obraSocialMenu.mostrar();
        break;
    case 6:

        break;
    case 7:

        break;
    case 8:
        _reporteMenu.mostrar();
        break;
    case 9:
        _configuracionMenu.mostrar();
        break;

        }
    }

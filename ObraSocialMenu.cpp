#include <iostream>
#include "ObraSocialMenu.h"

using namespace std;

    ObraSocialMenu::ObraSocialMenu(){
        _cantidadOpciones = 5;
    }

    void ObraSocialMenu::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void ObraSocialMenu::mostrarOpciones(){
        cout << "****** MENU OBRA SOCIAL ******" << endl;
        cout << "1. CARGAR OBRA SOCIAL" << endl;
        cout << "2. ELIMINAR OBRA SOCIAL" << endl;
        cout << "3. MODIFICAR DATOS" << endl;
        cout << "4. LISTAR" << endl;
        cout << "5. CONSULTAR" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "******************************" << endl;
    }

    int ObraSocialMenu::seleccionarOpciones(){
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

    void ObraSocialMenu::ejecutarOpciones(int opcion){
         switch(opcion){
    case 1:
       _obraSocialManager.cargar();
        break;
    case 2:
        _obraSocialManager.bajaLogica();
        break;
    case 3:
        _obraSocialModificarMenu.mostrar();
        break;
    case 4:
        _obraSocialManager.listadoOrdenNombre();
        break;
    case 5:
         _obraSocialManager.consultarNombre();
        break;

        }
    }

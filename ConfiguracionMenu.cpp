#include <iostream>
#include "ConfiguracionMenu.h"

using namespace std;

    ConfiguracionMenu::ConfiguracionMenu(){
        _cantidadOpciones = 2;
    }

    void ConfiguracionMenu::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void ConfiguracionMenu::mostrarOpciones(){
        cout << "*** MENU CONFIGURACION ***" << endl;
        cout << "1. CREAR COPIA DE SEGURIDAD" << endl;
        cout << "2. EXPORTAR DATOS" << endl;
        cout << "**************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "**************************" << endl;
    }

    int ConfiguracionMenu::seleccionarOpciones(){
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

    void ConfiguracionMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
        _configuracionMenuBackups.mostrar();
        break;
    case 2:
        _configuracionMenuExportarCSV.mostrar();
        break;
        }
    }

#include <iostream>
#include "ReporteMenu.h"

using namespace std;

    ReporteMenu::ReporteMenu(){
        _cantidadOpciones = 5;
    }

    void ReporteMenu::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void ReporteMenu::mostrarOpciones(){
        cout << "********* MENU REPORTE *********" << endl;
        cout << "1. FACRTURACION MENSUAL Y ANUAL" << endl;
        cout << "2. FACTURACION POR MEDICO" << endl;
        cout << "3. TURNOS POR ESPECIALIDAD" << endl;
        cout << "4. ATENCION POR OBRA SOCIAL" << endl;
        cout << "5. DIAGNOSTICOS FRECUENTES" << endl;
        cout << "********************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "********************************" << endl;
    }

    int ReporteMenu::seleccionarOpciones(){
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

    void ReporteMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
        _reporteManager.facturacionMensualYAnual();
        break;
    case 2:
        _reporteManager.facturacionPorMedico();
        break;
    case 3:
        _reporteManager.turnosPorEspecialidad();
        break;
    case 4:
        _reporteManager.atencionPorObraSocial();
        break;
    case 5:
        _reporteManager.diagnosticosFrecuentes();
        break;
        }

    }

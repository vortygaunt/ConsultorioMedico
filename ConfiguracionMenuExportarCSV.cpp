#include <iostream>
#include "ConfiguracionMenuExportarCSV.h"

using namespace std;

    ConfiguracionMenuExportarCSV::ConfiguracionMenuExportarCSV(){
        _cantidadOpciones = 7;
    }

    void ConfiguracionMenuExportarCSV::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void ConfiguracionMenuExportarCSV::mostrarOpciones(){
        cout << "*** MENU EXPORTAR DATOS CSV ***" << endl;
        cout << "1. EXPORTAR TURNO" << endl;
        cout << "2. EXPORTAR MEDICO" << endl;
        cout << "3. EXPORTAR PACIENTE" << endl;
        cout << "4. EXPORTAR CONSULTORIO" << endl;
        cout << "5. EXPORTAR OBRAS SOCIALES" << endl;
        cout << "6. EXPORTAR HISTORIA CLINICA" << endl;
        cout << "7. EXPORTAR ESPECIALIDADES" << endl;
        cout << "*********************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*********************************" << endl;
    }

    int ConfiguracionMenuExportarCSV::seleccionarOpciones(){
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

    void ConfiguracionMenuExportarCSV::ejecutarOpciones(int opcion){
           switch(opcion){
    case 1:
        _configuracionManager.exportarCSVTurno();
        break;
    case 2:
        _configuracionManager.exportarCSVMedico();
        break;
    case 3:
        _configuracionManager.exportarCSVPaciente();
        break;
    case 4:
        _configuracionManager.exportarCSVConsultorio();
        break;
    case 5:
        _configuracionManager.exportarCSVObraSocial();
        break;
    case 6:
        _configuracionManager.exportarCSVHistoriaClinica();
        break;
    case 7:
        _configuracionManager.exportarCSVEspecialidades();
        break;
        }
    }

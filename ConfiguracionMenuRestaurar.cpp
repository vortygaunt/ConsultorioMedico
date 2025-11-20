#include <iostream>
#include "ConfiguracionMenuRestaurar.h"

using namespace std;

    ConfiguracionMenuRestaurar::ConfiguracionMenuRestaurar(){
        _cantidadOpciones = 7;
    }

    void ConfiguracionMenuRestaurar::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            system("pause");
        }while(opcion != 0);
    }

    void ConfiguracionMenuRestaurar::mostrarOpciones(){
        cout << "******** MENU RESTAURAR ARVHIVOS ********" << endl;
        cout << "1. RESTAURAR ARCHIVO DE TURNO" << endl;
        cout << "2. RESTAURAR ARCHIVO DE MEDICO" << endl;
        cout << "3. RESTAURAR ARCHIVO DE PACIENTES" << endl;
        cout << "4. RESTAURAR ARCHIVO DE CONSULTORIO" << endl;
        cout << "5. RESTAURAR ARCHIVO DE OBRAS SOCIALES" << endl;
        cout << "6. RESTAURAR ARCHIVO DE HISTORIA CLINICA" << endl;
        cout << "7. RESTAURAR ARCHIVO DE ESPECIALIDADES" << endl;
        cout << "*****************************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*********************************" << endl;
    }

    int ConfiguracionMenuRestaurar::seleccionarOpciones(){
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

    void ConfiguracionMenuRestaurar::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
        _configuracionManager.restaurarArchvioTurno();
        break;
    case 2:
        _configuracionManager.restaurarArchvioMedico();
        break;
    case 3:
        _configuracionManager.restaurarArchvioPaciente();
        break;
    case 4:
        _configuracionManager.restaurarArchvioConsultorio();
        break;
    case 5:
        _configuracionManager.restaurarArchvioObraSocial();
        break;
    case 6:
        _configuracionManager.restaurarArchvioHistoriaClinica();
        break;
    case 7:
        _configuracionManager.restaurarArchvioEspecialidades();
        break;
        }
    }

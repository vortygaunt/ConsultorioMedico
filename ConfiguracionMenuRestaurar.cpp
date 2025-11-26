#include <iostream>
#include "ConfiguracionMenuRestaurar.h"

using namespace std;

    ConfiguracionMenuRestaurar::ConfiguracionMenuRestaurar(){
        _cantidadOpciones = 7;
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

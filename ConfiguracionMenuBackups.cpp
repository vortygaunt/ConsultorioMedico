#include <iostream>
#include "ConfiguracionMenuBackups.h"

using namespace std;

    ConfiguracionMenuBackups::ConfiguracionMenuBackups(){
        _cantidadOpciones = 7;
    }


    void ConfiguracionMenuBackups::mostrarOpciones(){
        cout << "*** MENU COPIAS DE SEGURIDAD ***" << endl;
        cout << "1. CREAR BACKUP DE TURNO" << endl;
        cout << "2. CREAR BACKUP DE MEDICO" << endl;
        cout << "3. CREAR BACKUP DE PACIENTES" << endl;
        cout << "4. CREAR BACKUP DE CONSULTORIO" << endl;
        cout << "5. CREAR BACKUP DE OBRAS SOCIALES" << endl;
        cout << "6. CREAR BACKUP DE HISTORIA CLINICA" << endl;
        cout << "7. CREAR BACKUP DE ESPECIALIDADES" << endl;
        cout << "*********************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*********************************" << endl;
    }



    void ConfiguracionMenuBackups::ejecutarOpciones(int opcion){
         switch(opcion){
    case 1:
        _configuracionManager.backupTurno();
        break;
    case 2:
        _configuracionManager.backupMedico();
        break;
    case 3:
        _configuracionManager.backupPaciente();
        break;
    case 4:
        _configuracionManager.backupConsultorio();
        break;
    case 5:
        _configuracionManager.backupObraSocial();
        break;
    case 6:
        _configuracionManager.backupHistoriaClinica();
        break;
    case 7:
        _configuracionManager.backupEspecialidades();
        break;
        }
    }

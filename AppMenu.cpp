#include <iostream>
#include "AppMenu.h"

using namespace std;

    AppMenu::AppMenu(){
        _cantidadOpciones = 9;
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



    void AppMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
        _turnoMenu.mostrar();
        break;
    case 2:
        _medicoMenu.mostrar();
        break;
    case 3:
        _pacienteMenu.mostrar();
        break;
    case 4:
        _consultorioMenu.mostrar();
        break;
    case 5:
         _obraSocialMenu.mostrar();
        break;
    case 6:
        _historiaClinicaMenu.mostrar();
        break;
    case 7:
        _especialidadMenu.mostrar();
        break;
    case 8:
        _reporteMenu.mostrar();
        break;
    case 9:
        _configuracionMenu.mostrar();
        break;

        }
    }

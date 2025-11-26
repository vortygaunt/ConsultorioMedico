#include <iostream>
#include "TurnoListarMenu.h"

using namespace std;

    TurnoListarMenu::TurnoListarMenu(){
        _cantidadOpciones = 4;
    }

    void TurnoListarMenu::mostrarOpciones(){
        cout << "******** MENU LISTAR ********" << endl;
        cout << "1. ORDENADO POR FECHA" << endl;
        cout << "2. FILTRADO POR MEDICO" << endl;
        cout << "3. FILTRADO POR PACIENTE" << endl;
        cout << "4. FILTRADO POR ESTADO" << endl;
        cout << "*****************************" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*****************************" << endl;
    }

    void TurnoListarMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
       _turnoManager.listadoOrdenFecha();
        break;
    case 2:
        _turnoManager.listadoFiltradoMedico();
        break;
    case 3:
        _turnoManager.listadoFiltradoPaciente();
        break;
    case 4:
        _turnoManager.listadoFiltradoEstado();
        break;

        }
    }

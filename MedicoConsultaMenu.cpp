#include <iostream>
#include "MedicoConsultaMenu.h"

using namespace std;

    MedicoConsultaMenu::MedicoConsultaMenu(){
        _cantidadOpciones = 4;
    }


    void MedicoConsultaMenu::mostrarOpciones(){
        cout << "************ MENU CONSULTAS ************" << endl;
        cout << "1. CONSULTAR POR DNI" << endl;
        cout << "2. CONSULTAR POR CODIGO DE ESPECIALIDAD" << endl;
        cout << "3. CONSULTAR POR MATRICULA" << endl;
        cout << "4. CONSULTAR POR ANTIGÜEDAD" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "****************************************" << endl;
    }



    void MedicoConsultaMenu::ejecutarOpciones(int opcion){
        switch(opcion){
    case 1:
       _medicoManager.consultarDni();
        break;
    case 2:
        _medicoManager.consultarCodigoEspecialidad();
        break;
    case 3:
        _medicoManager.consultarMatricula();
        break;
    case 4:
        _medicoManager.consultarAntiguedad();
        break;
        }
    }


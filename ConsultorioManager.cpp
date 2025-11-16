#include <iostream>
#include "ConsultorioManager.h"

using namespace std;

    ConsultorioManager::ConsultorioManager(){

    }

    void ConsultorioManager::cargar(){
        int numeroConsultorio;
        int pisoConsultorio;
        int codigoEspecialidad;
        bool ocupado;
        int idMedico = 0;

        cout << "Ingrese el numero de consultorio: ";
        cin >> numeroConsultorio;

        cout << "Ingrese el piso del consultorio: ";
        cin >> pisoConsultorio;

        cout << "Ingrese el codigo de especialidad: ";
        cin >> codigoEspecialidad;

        cout << "Esta ocupado? 1-si 0-no: ";
        cin >> ocupado;

        if(ocupado){
            cout << "Ingrese el ID del medico que esta ocupando el consultorio: ";
            cin >> idMedico;
        }

        if(_repo.guardar(Consultorio(numeroConsultorio, pisoConsultorio, codigoEspecialidad, ocupado, idMedico, true))){
            cout << "El consultorio se guardo correctamente." << endl;
        }else{
            cout << "Hubo un error al intentar guardar el consultorio." << endl;
        }
    }

    void ConsultorioManager::bajaLogica(){
        int cantidad, numeroConsultorio, pos = -1;
        Consultorio registro;

        cout << "Ingrese el numero del consultorio que desea dar de baja: ";
        cin >> numeroConsultorio;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);
            if(numeroConsultorio == registro.getNumeroConsultorio() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.eliminar(pos)){
                cout << "El consultorio fue dado de baja correctamente." << endl;
            }else{
                cout << "No se pudo dar de baja al consultorio." << endl;
            }
        }else{
            cout << "No se encontro ningún consultorio con ese numero." << endl;
        }
    }

     void ConsultorioManager::listadoOrdenNumero(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay consultorios cargados." << endl;
            return;
        }

        Consultorio *consultorios;

        consultorios = new Consultorio[cantidad];

        for(int i=0; i<cantidad; i++){
            consultorios[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(consultorios[j].getNumeroConsultorio() > consultorios[j+1].getNumeroConsultorio()){
                    Consultorio aux = consultorios[j];
                    consultorios[j] = consultorios[j+1];
                    consultorios[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break; /// corta el ciclo si ya esta ordenado
            }
        }

        for(int i=0; i<cantidad; i++){
            if(consultorios[i].getEstado()){
                consultorios[i].mostrar();
            }
        }

        delete[] consultorios;
     }

     void ConsultorioManager::listadoOrdenPiso(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay consultorios cargados." << endl;
            return;
        }

        Consultorio *consultorios;

        consultorios = new Consultorio[cantidad];

        for(int i=0; i<cantidad; i++){
            consultorios[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(consultorios[j].getPisoConsultorio() > consultorios[j+1].getPisoConsultorio()){
                    Consultorio aux = consultorios[j];
                    consultorios[j] = consultorios[j+1];
                    consultorios[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break; /// corta el ciclo si ya esta ordenado
            }
        }

        for(int i=0; i<cantidad; i++){
            if(consultorios[i].getEstado()){
                consultorios[i].mostrar();
            }
        }

        delete[] consultorios;
     }

    void ConsultorioManager::consultarNumeroConsultorio(){
        int numeroConsultorio;
        Consultorio registro;
        int cantidad;
        bool encontrado = false;

        cout << "Ingrese el numero de consultorio: ";
        cin >> numeroConsultorio;

        cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(numeroConsultorio == registro.getNumeroConsultorio() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encontro ningún consultorio con ese numero." << endl;
        }
    }

     void ConsultorioManager::modificarCodigoEspecialidad(){
        int codigoEspecialidad, numeroConsultorio, cantidad, pos = -1;
        Consultorio registro;

        cout << "Ingrese el numero del consultorio: ";
        cin >> numeroConsultorio;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(numeroConsultorio == registro.getNumeroConsultorio() && registro.getEstado()){
                cout << "Ingrese el nuevo codigo de especialidad: ";
                cin >> codigoEspecialidad;
                registro.setCodigoEspecialidad(codigoEspecialidad);
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.modificar(pos, registro)){
                    cout << "El codigo de especialidad se modificó con éxito." << endl;
            } else {
                    cout << "No se pudo modificar el codigo de especialidad." << endl;
            }
        } else {
                cout << "No se encontró ningún consultorio con ese numero." << endl;
        }
     }



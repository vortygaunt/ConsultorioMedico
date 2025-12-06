#include <iostream>
#include "ConsultorioManager.h"
#include "funcionesGlobales.h"

using namespace std;

    ConsultorioManager::ConsultorioManager(){

    }

    void ConsultorioManager::cargar(){
        bool existeConsultorio;
        int numeroConsultorio;
        int pisoConsultorio;
        int codigoEspecialidad;
        int ocupado;
        int idMedico;

        do{
            existeConsultorio = false;

            numeroConsultorio = leerEntero("Ingrese el numero de consultorio: ");

            if(numeroConsultorio <= 0){
                cout << "Numero de consultorio invalido." << endl;
            }

            if(_repo.existeConsultorio(numeroConsultorio)){
                cout << "Ya existe un consultorio con ese numero." << endl;
                existeConsultorio = true;
            }

        }while(numeroConsultorio <= 0 || existeConsultorio);

        do{
            pisoConsultorio = leerEntero("Ingrese el piso del consultorio: ");

            if(pisoConsultorio <= 0){
                cout << "Piso del consultorio invalido." << endl;
            }

        }while(pisoConsultorio <= 0);

        do{
            codigoEspecialidad = leerEntero("Ingrese el codigo de especialidad: ");

            if(codigoEspecialidad <= 0){
                cout << "Codigo de especialidad invalido." << endl;
            }

        }while(codigoEspecialidad <= 0);

        do{
            ocupado = leerEntero("Esta ocupado? 1-si 0-no: ");

            if(ocupado != 0 && ocupado != 1){
                cout << "Ingrese 1 o 0." << endl;
            }

        }while(ocupado != 0 && ocupado != 1);

        if(ocupado){
            idMedico = leerEntero("Ingrese el ID del medico que esta ocupando el consultorio: ");

            while(!_repoMedico.existeID(idMedico)){
                cout << "No existe ningun medico con ese ID." << endl;
                idMedico = leerEntero("Ingrese nuevamente el ID del medico: ");
            }
        }else{
            idMedico = 0;
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

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        numeroConsultorio = leerEntero("Ingrese el numero del consultorio que desea dar de baja: ");
        if(numeroConsultorio <= 0){
            cout << "Numero de consultorio invalido." << endl;
            return;
        }

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

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        numeroConsultorio = leerEntero("Ingrese el numero del consultorio que desea consultar: ");
        if(numeroConsultorio <= 0){
            cout << "Numero de consultorio invalido." << endl;
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

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        numeroConsultorio = leerEntero("Ingrese el numero del consultorio: ");
        if(numeroConsultorio <= 0){
            cout << "Numero de consultorio invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

        if(numeroConsultorio == registro.getNumeroConsultorio() && registro.getEstado()){
            pos = i;
            break;
            }
        }

        if(pos == -1){
            cout << "No se encontro ningun consultorio con ese numero." << endl;
            return;
        }

        do{
            codigoEspecialidad = leerEntero("Ingrese el nuevo codigo de especialidad: ");
            if(codigoEspecialidad <= 0){
                cout << "Codigo de especialidad invalido." << endl;
            }
        }while(codigoEspecialidad <= 0);

        registro.setCodigoEspecialidad(codigoEspecialidad);

        if(_repo.modificar(pos, registro)){
                cout << "El codigo de especialidad se modificó con éxito." << endl;
        } else {
                cout << "No se pudo modificar el codigo de especialidad." << endl;
        }

     }



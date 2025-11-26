#include <iostream>
#include "EspecialidadManager.h"
#include "funcionesGlobales.h"

using namespace std;

    EspecialidadManager::EspecialidadManager(){
    }

    void EspecialidadManager::cargar(){
        int codigoEspecialidad;
        string descripcion;
        bool valido;

        do{
        codigoEspecialidad = leerEntero("Ingrese el codigo de especialidad: ");
        if(codigoEspecialidad <= 0){
            cout << "Codigo invalido." << endl;
        }

        }while(codigoEspecialidad <= 0);

        do{
        cout << "Ingrese la descripcion: ";
        descripcion = cargarCadena();

        valido = soloLetras(descripcion);
        if(!valido){
            cout << "Descripcion invalida." << endl;
        }

        }while(!valido);

        if(_repo.guardar(Especialidad(codigoEspecialidad, descripcion, true))){
            cout << "La especialidad se guardo correctamente." << endl;
        }else{
            cout << "Hubo un error al guardar la especialidad." << endl;
        }
    }

    void EspecialidadManager::bajaLogica(){
        int cantidad, codEspecialidad, pos = -1;
        Especialidad registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros en el archivo." << endl;
            return;
        }

        codEspecialidad = leerEntero("Ingrese el codigo de especialidad que desea eliminar: ");
        if(codEspecialidad <= 0){
            cout << "Codigo invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);
            if(codEspecialidad == registro.getCodigoEspecialidad() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.eliminar(pos)){
                cout << "La especialidad fue eliminada correctamente." << endl;
            }else{
                cout << "No se pudo eliminar la especialidad." << endl;
            }
        }else{
            cout << "No se encontro ninguna especialidad con ese codigo." << endl;
        }
    }

    void EspecialidadManager::modificarDescripcion(){
        string descripcion;
        bool valido;
        int codEspecialidad, cantidad, pos = -1;
        Especialidad registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        codEspecialidad = leerEntero("Ingrese el codigo de especialidad: ");
        if(codEspecialidad <= 0){
            cout << "Codigo invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(codEspecialidad == registro.getCodigoEspecialidad() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro una especialidad con ese codigo." << endl;
            return;
        }

        cout << "Ingrese la descripcion nueva: ";
        descripcion = cargarCadena();

        valido = soloLetras(descripcion);

        if(!valido){
            cout << "Descripcion no valida." << endl;
            return;
        }

        registro.setDescripcion(descripcion);

        if(_repo.modificar(pos, registro)){
                    cout << "La descripcion se modifico con exito." << endl;
            } else {
                    cout << "No se pudo modificar la descripcion." << endl;
            }
    }

    void EspecialidadManager::listadoOrdenDescripcion(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay medicos cargados." << endl;
            return;
        }

        Especialidad *especialidades;

        especialidades = new Especialidad[cantidad];

        for(int i=0; i<cantidad; i++){
            especialidades[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(especialidades[j].getDescripcion() > especialidades[j+1].getDescripcion()){
                    Especialidad aux = especialidades[j];
                    especialidades[j] = especialidades[j+1];
                    especialidades[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break; /// corta el ciclo si ya esta ordenado
            }
        }

        for(int i=0; i<cantidad; i++){
            if(especialidades[i].getEstado()){
                especialidades[i].mostrar();
            }
        }

        delete[] especialidades;
    }

    void EspecialidadManager::consultaDescripcion(){
        bool valido;
        string descripcion;
        Especialidad registro;
        int cantidad;
        bool encontrado = false;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        do{
            cout << "Ingrese la descripcion de la especialidad que desea consultar: ";
            descripcion = cargarCadena();

            valido = soloLetras(descripcion);

            if(!valido){
                cout << "Descripcion invalida." << endl;
            }
        }while(!valido);

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(descripcion == registro.getDescripcion() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encontro ninguna especialidad con esa descripcion." << endl;
        }
    }

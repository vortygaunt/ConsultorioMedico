#include <iostream>
#include "ObraSocialManager.h"
#include "funcionesGlobales.h"

using namespace std;

    void ObraSocialManager::cargar(){
        int idObraSocial;
        string nombre;
        string telefonoObraSocial;

        idObraSocial = _repo.getnuevoID();

        cout << "Ingrese el nombre de la obra social: ";
        nombre = cargarCadena();

        cout << "Ingrese el telefono: ";
        telefonoObraSocial = cargarCadena();

        if(_repo.guardar(ObraSocial(idObraSocial, nombre, telefonoObraSocial, true))){
            cout << "La obra social se guardo correctamente." << endl;
        }else{
            cout << "Hubo un error al intentar guardar la obra social." << endl;
        }
    }

    void ObraSocialManager::bajaLogica(){
        int cantidad, idObraSocial, pos = -1;
        ObraSocial registro;

        cout << "Ingrese el ID de la obra social que desea eliminar: ";
        cin >> idObraSocial;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);
            if(idObraSocial == registro.getIdObraSocial() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.eliminar(pos)){
                cout << "La obra social fue dado de baja correctamente." << endl;
            }else{
                cout << "No se pudo dar de baja a la obra social." << endl;
            }
        }else{
            cout << "No se encontro ninguna obra social con ese ID." << endl;
        }
    }

    void ObraSocialManager::listadoOrdenNombre(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay obras sociales cargadas." << endl;
            return;
        }

        ObraSocial *obrasSociales;

        obrasSociales = new ObraSocial[cantidad];

        for(int i=0; i<cantidad; i++){
            obrasSociales[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(obrasSociales[j].getNombre() > obrasSociales[j+1].getNombre()){
                    ObraSocial aux = obrasSociales[j];
                    obrasSociales[j] = obrasSociales[j+1];
                    obrasSociales[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break; /// corta el ciclo si ya esta ordenado
            }
        }

        for(int i=0; i<cantidad; i++){
            if(obrasSociales[i].getEstado()){
                obrasSociales[i].mostrar();
            }
        }

        delete[] obrasSociales;
    }

    void ObraSocialManager::consultarNombre(){
        string nombre;
        ObraSocial registro;
        int cantidad;
        bool encontrado = false;

        cout << "Ingrese el nombre de la obra social que desea consultar: ";
        nombre = cargarCadena();

        cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(nombre == registro.getNombre() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encontro ninguna obra social con ese nombre." << endl;
        }
    }

     void ObraSocialManager::modificarNombre(){
        string nombre;
        int id, cantidad, pos = -1;
        ObraSocial registro;

        cout << "Ingrese el ID de la obra social: ";
        cin >> id;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdObraSocial() && registro.getEstado()){
                cout << "Ingrese el nuevo nombre: ";
                nombre = cargarCadena();
                registro.setNombre(nombre);
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.modificar(pos, registro)){
                    cout << "El nombre se modificó con éxito." << endl;
            } else {
                    cout << "No se pudo modificar el nombre." << endl;
            }
        } else {
                cout << "No se encontró ninguna obra social con ese ID." << endl;
        }
     }

      void ObraSocialManager::modificarTelefono(){
        string telefono;
        int id, cantidad, pos = -1;
        ObraSocial registro;

        cout << "Ingrese el ID de la obra social: ";
        cin >> id;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdObraSocial() && registro.getEstado()){
                cout << "Ingrese el nuevo telefono: ";
                telefono = cargarCadena();
                registro.setTelefonoObraSocial(telefono);
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.modificar(pos, registro)){
                    cout << "El telefono se modificó con éxito." << endl;
            } else {
                    cout << "No se pudo modificar el telefono." << endl;
            }
        } else {
                cout << "No se encontró ninguna obra social con ese ID." << endl;
        }
      }

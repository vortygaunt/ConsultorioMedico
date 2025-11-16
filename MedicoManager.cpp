#include <iostream>
#include "MedicoManager.h"
#include "Fecha.h"
#include "funcionesGlobales.h"
using namespace std;

    MedicoManager::MedicoManager(){

    }

    void MedicoManager::cargar(){
        int idMedico;
        string dniMedico;
        string nombreMedico;
        string apellidoMedico;
        string telefonoMedico;
        string emailMedico;
        string matricula;
        int codigoEspecialidad;
        Fecha fechaInicio;

        idMedico = _repo.getnuevoID();

        cout << "Ingrese el DNI: ";
        dniMedico = cargarCadena();

        cout << "Ingrese el nombre: ";
        nombreMedico = cargarCadena();

        cout << "Ingrese el apellido: ";
        apellidoMedico = cargarCadena();

        cout << "Ingrese el telefono: ";
        telefonoMedico = cargarCadena();

        cout << "Ingrese el email: ";
        emailMedico = cargarCadena();

        cout << "Ingrese la matricula: ";
        matricula = cargarCadena();

        cout << "Ingrese el codigo de especialidad: ";
        cin >> codigoEspecialidad;

        cout << "Ingrese la fecha de inicio: ";
        fechaInicio.cargar();

        if(_repo.guardar(Medico(idMedico, dniMedico, nombreMedico, apellidoMedico, telefonoMedico, emailMedico, matricula, codigoEspecialidad, fechaInicio, true))){
            cout << "El médico se guardo correctamente." << endl;
        }else{
            cout << "Hubo un error al intentar guardar al médico." << endl;
        }

    }

    void MedicoManager::listadoOrdenApellido(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay medicos cargados." << endl;
            return;
        }

        Medico *medicos;

        medicos = new Medico[cantidad];

        for(int i=0; i<cantidad; i++){
            medicos[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(medicos[j].getApellidoMedico() > medicos[j+1].getApellidoMedico()){
                    Medico aux = medicos[j];
                    medicos[j] = medicos[j+1];
                    medicos[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break; /// corta el ciclo si ya esta ordenado
            }
        }

        for(int i=0; i<cantidad; i++){
            if(medicos[i].getEstado()){
                medicos[i].mostrar();
            }
        }

        delete[] medicos;

    }

    void MedicoManager::listadoOrdenEspecialidad(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay medicos cargados." << endl;
            return;
        }

        Medico *medicos;

        medicos = new Medico[cantidad];

        for(int i=0; i<cantidad; i++){
            medicos[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(medicos[j].getCodigoEspecialidad() > medicos[j+1].getCodigoEspecialidad()){
                    Medico aux = medicos[j];
                    medicos[j] = medicos[j+1];
                    medicos[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break; /// corta el ciclo si ya esta ordenado
            }
        }

        for(int i=0; i<cantidad; i++){
            if(medicos[i].getEstado()){
                medicos[i].mostrar();
            }
        }

        delete[] medicos;
    }

    void MedicoManager::listadoOrdenAntiguedad(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay medicos cargados." << endl;
            return;
        }

        Medico *medicos;

        medicos = new Medico[cantidad];

        for(int i=0; i<cantidad; i++){
            medicos[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(medicos[j].getFechaInicio() > medicos[j+1].getFechaInicio()){
                    Medico aux = medicos[j];
                    medicos[j] = medicos[j+1];
                    medicos[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break; /// corta el ciclo si ya esta ordenado
            }
        }

        for(int i=0; i<cantidad; i++){
            if(medicos[i].getEstado()){
                medicos[i].mostrar();
            }
        }

        delete[] medicos;
    }

    void MedicoManager::bajaLogica(){
        int cantidad, id, pos = -1;
        Medico registro;

        cout << "Ingrese el ID del médico que desea eliminar: ";
        cin >> id;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);
            if(id == registro.getIdMedico() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.eliminar(pos)){
                cout << "El médico fue eliminado correctamente." << endl;
            }else{
                cout << "No se pudo eliminar al médico." << endl;
            }
        }else{
            cout << "No se encontro ningún médico con ese ID." << endl;
        }

    }

    void MedicoManager::modificarTelefono(){
        string telefono;
        int id, cantidad, pos = -1;
        Medico registro;

        cout << "Ingrese el ID del médico: ";
        cin >> id;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdMedico() && registro.getEstado()){
                cout << "Ingrese el nuevo telefono: ";
                telefono = cargarCadena();
                registro.setTelefonoMedico(telefono);
                pos = i;
                break;
            }
        }

       if(pos != -1){
            if(_repo.modificar(pos, registro)){
                    cout << "El teléfono se modificó con éxito." << endl;
            } else {
                    cout << "No se pudo modificar el teléfono." << endl;
            }
        } else {
                cout << "No se encontró ningún médico con ese ID." << endl;
        }
    }

    void MedicoManager::modificarEmail(){
        string email;
        int id, cantidad, pos = -1;
        Medico registro;

        cout << "Ingrese el ID del médico: ";
        cin >> id;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdMedico() && registro.getEstado()){
                cout << "Ingrese el nuevo e-mail: ";
                email = cargarCadena();
                registro.setEmailMedico(email);
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.modificar(pos, registro)){
                    cout << "El e-mail se modificó con éxito." << endl;
            } else {
                    cout << "No se pudo modificar el e-mail." << endl;
            }
        } else {
                cout << "No se encontró ningún médico con ese ID." << endl;
        }
     }

     void MedicoManager::modificarCodigoEspecialidad(){
        int codigoEspecialidad, id, cantidad, pos = -1;
        Medico registro;

        cout << "Ingrese el ID del médico: ";
        cin >> id;

        cantidad = _repo.getCantidadRegistro();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdMedico() && registro.getEstado()){
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
                cout << "No se encontró ningún médico con ese ID." << endl;
        }
     }

     void MedicoManager::consultarDni(){
        string dni;
        Medico registro;
        int cantidad;
        bool encontrado = false;

        cout << "Ingrese el DNI del medico que desea consultar: ";
        dni = cargarCadena();

        cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(dni == registro.getDniMedico() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encontro ningún médico con ese DNI." << endl;
        }
     }

     void MedicoManager::consultarCodigoEspecialidad(){
        Medico registro;
        int codigoEspecialidad, cantidad;
        bool encontrado = false;

        cout << "Ingrese el código de la especialidad que le interesa consultar: ";
        cin >> codigoEspecialidad;

        cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(codigoEspecialidad == registro.getCodigoEspecialidad() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;

            }
        }

        if(!encontrado){
            cout << "No se encontro ningún médico que tenga ese código de especialidad." << endl;
        }
     }

     void MedicoManager::consultarMatricula(){
        string matricula;
        Medico registro;
        int cantidad;
        bool encontrado = false;

        cout << "Ingrese la matrícula del médico que desea consultar: ";
        matricula = cargarCadena();

        cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(matricula == registro.getMatricula() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encontro ningún médico con esa matrícula." << endl;
        }
     }

     void MedicoManager::consultarAntiguedad(){
        Fecha antiguedad;
        Medico registro;
        int cantidad;
        bool encontrado = false;

        cout << "Ingrese la fecha que desea consultar: " << endl;
        antiguedad.cargar();

        cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(antiguedad == registro.getFechaInicio() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;

            }
        }

        if(!encontrado){
            cout << "No se encontro ningún médico que haya iniciado en esa fecha." << endl;
        }
     }

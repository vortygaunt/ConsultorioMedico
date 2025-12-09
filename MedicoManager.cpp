#include <iostream>
#include "MedicoManager.h"
#include "Fecha.h"
#include "funcionesGlobales.h"

using namespace std;

    MedicoManager::MedicoManager(){

    }

    void MedicoManager::cargar(){
        bool valido;
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
        do{
            cout << "Ingrese el DNI: ";
            dniMedico = cargarCadena();

            valido = soloDigitos(dniMedico);

            if (dniMedico.size() < 7 || dniMedico.size() > 11) {
                valido = false;
            }

            if(!valido){
                cout << "DNI invalido." << endl;
            }

        }while(!valido);

        do{
            cout << "Ingrese el nombre: ";
            nombreMedico = cargarCadena();

            valido = soloLetras(nombreMedico);

            if(!valido){
                cout << "Nombre invalido." << endl;
            }

        }while(!valido);

        do{
            cout << "Ingrese el apellido: ";
            apellidoMedico = cargarCadena();

            valido = soloLetras(apellidoMedico);

            if(!valido){
                cout << "Apellido invalido." << endl;
            }

        }while(!valido);

        do{
            cout << "Ingrese el telefono: ";
            telefonoMedico = cargarCadena();

            valido = soloDigitos(telefonoMedico);

            if (telefonoMedico.size() < 6 || telefonoMedico.size() > 15) {
                valido = false;
            }

            if(!valido){
                cout << "Telefono invalido." << endl;
            }

        }while(!valido);

        cout << "Ingrese el email: ";
        emailMedico = cargarCadena();

        do{
            cout << "Ingrese la matricula: ";
            matricula = cargarCadena();

            valido = soloDigitosyLetras(matricula);

            if(!valido){
                cout << "Matricula invalida." << endl;
            }

        }while(!valido);

        do{
            codigoEspecialidad = leerEntero("Ingrese el codigo de especialidad: ");

            if(codigoEspecialidad <= 0){
                cout << "Codigo invalido." << endl;
            }

        }while(codigoEspecialidad <= 0);

        cout << "Ingrese la fecha de inicio: " << endl;
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

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros en el archivo." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del medico que desea eliminar: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);
            if(id == registro.getIdMedico() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos != -1){
            if(_repo.eliminar(pos)){
                cout << "El medico fue eliminado correctamente." << endl;
            }else{
                cout << "No se pudo eliminar al medico." << endl;
            }
        }else{
            cout << "No se encontro ningun medico con ese ID." << endl;
        }

    }

    void MedicoManager::modificarTelefono(){
        string telefono;
        bool valido;
        int id, cantidad, pos = -1;
        Medico registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del medico: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdMedico() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro un medico con ese ID." << endl;
            return;
        }

        cout << "Ingrese el telefono nuevo: ";
        telefono = cargarCadena();

        valido = soloDigitos(telefono);

        if(!valido){
            cout << "Telfono no valido." << endl;
            return;
        }

        registro.setTelefonoMedico(telefono);

        if(_repo.modificar(pos, registro)){
                    cout << "El telefono se modifico con exito." << endl;
            } else {
                    cout << "No se pudo modificar el telefono." << endl;
            }

    }

    void MedicoManager::modificarEmail(){
        string email;
        int id, cantidad, pos = -1;
        Medico registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del medico: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdMedico() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro un medico con ese ID." << endl;
            return;
        }

        cout << "Ingrese el nuevo e-mail: ";
        email = cargarCadena();

        registro.setEmailMedico(email);

        if(_repo.modificar(pos, registro)){
                cout << "El e-mail se modifico con exito." << endl;
        } else {
                cout << "No se pudo modificar el e-mail." << endl;
            }

    }

    void MedicoManager::modificarCodigoEspecialidad(){
        int codigoEspecialidad, id, cantidad, pos = -1;
        Medico registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros en el archivo." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del medico: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getIdMedico() && registro.getEstado()){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro un medico con ese ID." << endl;
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
                cout << "El codigo de especialidad se modifico con exito." << endl;
        } else {
                cout << "No se pudo modificar el codigo de especialidad." << endl;
        }
    }

    void MedicoManager::consultarDni(){
        bool valido;
        string dni;
        Medico registro;
        int cantidad;
        bool encontrado = false;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        do{
            cout << "Ingrese el DNI del medico que desea consultar: ";
            dni = cargarCadena();

            valido = soloDigitos(dni);

            if(dni.size() < 7 || dni.size() > 11){
                valido = false;
            }

            if(!valido){
                cout << "DNI invalido." << endl;
            }
        }while(!valido);

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(dni == registro.getDniMedico() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encontro ningun medico con ese DNI." << endl;
        }
    }

    void MedicoManager::consultarCodigoEspecialidad(){
        Medico registro;
        int codigoEspecialidad, cantidad;
        bool encontrado = false;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        codigoEspecialidad = leerEntero("Ingrese el codigo de especialidad del medico que desea consultar: ");
        if(codigoEspecialidad <= 0){
            cout << "Codigo de especialidad invalido." << endl;
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
            cout << "No se encontro ningun medico que tenga ese codigo de especialidad." << endl;
        }
    }

    void MedicoManager::consultarMatricula(){
        string matricula;
        Medico registro;
        int cantidad;
        bool encontrado = false;
        bool valido = false;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        do{
            cout << "Ingrese la matricula del medico que desea consultar: ";
            matricula = cargarCadena();

            valido = soloDigitosyLetras(matricula);

            if(!valido){
                cout << "Matricula invalida." << endl;
            }

        }while(!valido);

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(matricula == registro.getMatricula() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;
                break;
            }
        }

        if(!encontrado){
            cout << "No se encontro ningun medico con esa matricula." << endl;
        }
    }

    void MedicoManager::consultarAntiguedad(){
        Fecha antiguedad;
        Medico registro;
        int cantidad;
        bool encontrado = false;


        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        cout << "Ingrese la fecha que desea consultar: " << endl;
        antiguedad.cargar();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(antiguedad == registro.getFechaInicio() && registro.getEstado()){
                registro.mostrar();
                encontrado = true;

            }
        }

        if(!encontrado){
            cout << "No se encontro ningun medico que haya iniciado en esa fecha." << endl;
        }
    }



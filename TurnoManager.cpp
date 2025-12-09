#include <iostream>
#include "TurnoManager.h"
#include "Fecha.h"
#include "Hora.h"
#include "funcionesGlobales.h"

using namespace std;

    TurnoManager::TurnoManager(){
    }

    void TurnoManager::cargar(){
        int id;
        string dniPaciente;
        int idMedico;
        Fecha fechaAtencion;
        Hora horaAtencion;
        float importeConsulta;
        int numeroConsultorio;
        bool valido;
        int codigoEspecialidad;
        int idObraSocial;

        id = _repo.getNuevoID();

        do{
            cout << "Ingrese el DNI del paciente: ";
            dniPaciente = cargarCadena();

            valido = soloDigitos(dniPaciente);

            if (dniPaciente.size() < 7 || dniPaciente.size() > 11) {
                valido = false;
            }

            if(!valido){
                cout << "DNI invalido." << endl;
            }
        }while(!valido);

        do{
            valido = true;

            idMedico = leerEntero("Ingrese el ID del medico: ");

            if(!_repoMedico.existeID(idMedico)){
                cout << "El ID ingresado no existe. Intente nuevamente."<<endl;
                valido = false;
            }

        }while(!valido);

        cout << "Ingrese la fecha de atencion: " << endl;
        fechaAtencion.cargar();

        cout << "Ingrese la hora de atencion: " << endl;
        horaAtencion.cargar();

        do{
            importeConsulta = leerFloat("Ingrese el importe de consulta: ");
            if(importeConsulta < 0){
                cout << "Importe invalido." << endl;
            }

        }while(importeConsulta < 0);

        do{
            valido = true;

            numeroConsultorio = leerEntero("Ingrese el numero de consultorio: ");

            if(!_repoConsultorio.existeConsultorio(numeroConsultorio)){
                cout << "No existe un consultorio con ese numero." << endl;
                valido = false;
            }

            if(!_repoConsultorio.usarConsultorio(numeroConsultorio, idMedico)){
               cout << "Consultorio no disponible. Ingrese nuevamente otro consultrio."<< endl;
               valido = false;
            }

        }while(!valido);


        do {
            valido = true;

            codigoEspecialidad = leerEntero("Ingrese el codigo de especialidad: ");

            if (!_repoEspecialidad.existeCodigo(codigoEspecialidad)){
                cout << "El codigo ingresado no existe. Intente nuevamente. " << endl;
                valido = false;
            }

        } while (!valido);

        do {
            valido = true;

            idObraSocial = leerEntero("Ingrese el codigo de la Obra Social: ");

            if (!_repoObraSocial.existeCodigo(idObraSocial)){
                cout << "El codigo ingresado no existe. Intente nuevamente. " << endl;
                valido = false;
            }

        } while (!valido);

        if(_repo.guardar(Turno(id, dniPaciente, idMedico, fechaAtencion, horaAtencion, importeConsulta, numeroConsultorio, codigoEspecialidad, idObraSocial, 1))){
            cout << "EL turno se guardo correctamente." << endl;
        }else{
            cout << "Hubo un error al intentar guardar el turno." << endl;
        }
    }



    void TurnoManager::bajaLogica(){
        int cantidad, id, pos = -1;
        Turno registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros en el archivo." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del turno que desea cancelar: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);
            if(id == registro.getID() && registro.getEstado() != 0){
                pos = i;
                break;
            }
        }

        if(pos == -1){
          cout << "No se encontro nigun turno con ese ID."<< endl;
          return;
        }

        int _consultorio = registro.getNumeroConsultorio();
        registro.setEstado(false);

        if(_repo.modificar(pos, registro)){
            cout << "El turno fue cancelado correctamente." << endl;
            _repoConsultorio.liberarConsultorio(_consultorio);
        }
        else{
            cout << "No se pudo cancelar el turno." << endl;
        }
    }

    void TurnoManager::modificarFecha(){
        Fecha fechaNueva;
        int id, cantidad, pos = -1;
        Turno registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del Turno: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getID() && registro.getEstado() != 0){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro un turno con ese ID." << endl;
            return;
        }

        cout << "Ingrese la fecha nueva: ";
        fechaNueva.cargar();

        registro.setFechaAtencion(fechaNueva);

        if(_repo.modificar(pos, registro)){
            cout << "La fecha se modifico con exito." << endl;
        } else {
            cout << "No se pudo modificar el telefono." << endl;
        }
    }

    void TurnoManager::modificarHora(){
        Hora horaNueva;
        int id, cantidad, pos = -1;
        Turno registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del turno: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getID() && registro.getEstado() != 0){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro un turno con ese ID." << endl;
            return;
        }

        cout << "Ingrese la nueva hora: ";
        horaNueva.cargar();

        registro.setHoraAtencion(horaNueva);

        if(_repo.modificar(pos, registro)){
                    cout << "La hora se modifico con exito." << endl;
            } else {
                    cout << "No se pudo modificar la hora." << endl;
            }
    }

    void TurnoManager::modificarNumeroConsultorio(){
        int numeroNuevo, consultorioViejo;
        int id, cantidad, pos = -1;
        Turno registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del Turno: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getID() && registro.getEstado() != 0){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro un turno con ese ID." << endl;
            return;
        }

        numeroNuevo = leerEntero("Ingrese el numero de consultorio nuevo: ");

        if(numeroNuevo <= 0){
            cout << "Numero de consultorio invalido." << endl;
            return;
        }

        consultorioViejo = registro.getNumeroConsultorio();

        if(!_repoConsultorio.usarConsultorio(numeroNuevo, registro.getIdMedico())){
            cout << "Consultorio no disponible." << endl;
            return;
        }

        registro.setNumeroConsultorio(numeroNuevo);

        if(_repo.modificar(pos, registro)){
                    cout << "El Numero de consultorio se modifico con exito." << endl;
            } else {
                    cout << "No se pudo modificar el numero de consultorio." << endl;
            }

            _repoConsultorio.liberarConsultorio(consultorioViejo);
    }

    void TurnoManager::modificarImporte(){
        float importeNuevo;
        int id, cantidad, pos = -1;
        Turno registro;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay archivos en el registro." << endl;
            return;
        }

        id = leerEntero("Ingrese el ID del Turno: ");
        if(id <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(id == registro.getID() && registro.getEstado() != 0){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            cout << "No se encontro un turno con ese ID." << endl;
            return;
        }

        importeNuevo = leerFloat("Ingrese el nuevo importe: ");

        if(importeNuevo < 0){
            cout << "Importe invalido." << endl;
            return;
        }

        registro.setImporteConsulta(importeNuevo);

        if(_repo.modificar(pos, registro)){
                    cout << "El importe se modifico con exito." << endl;
            } else {
                    cout << "No se pudo modificar el importe." << endl;
            }
    }

    void TurnoManager::listadoOrdenFecha(){
        int cantidad = _repo.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay turnos cargados." << endl;
            return;
        }

        Turno *turnos;

        turnos = new Turno[cantidad];

        for(int i=0; i<cantidad; i++){
            turnos[i] = _repo.leer(i);
        }

        for(int i=0; i<cantidad-1; i++){
            bool intercambio = false;
            for(int j=0; j<cantidad-i-1; j++){
                if(turnos[j].getFechaAtencion() > turnos[j+1].getFechaAtencion()){
                    Turno aux = turnos[j];
                    turnos[j] = turnos[j+1];
                    turnos[j+1] = aux;
                    intercambio = true;
                }
            }
            if(!intercambio){
                break;
            }
        }

        for(int i=0; i<cantidad; i++){
            if(turnos[i].getEstado() != 0){
                turnos[i].mostrar();
            }
        }

        delete[] turnos;
    }

   void TurnoManager::listadoFiltradoMedico(){
        int idMedico = leerEntero("Ingrese el ID del medico: ");
        if(idMedico <= 0){
            cout << "ID invalido." << endl;
            return;
        }

        int cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay turnos cargados." << endl;
            return;
        }

        bool encontrado = false;
        Turno reg;

        cout << " Turnos del medico con el ID: " << idMedico << endl;
        cout << "--------------------------------------" << endl;

        for(int i = 0; i < cantidad; i++){
            reg = _repo.leer(i);

            if(reg.getEstado() == 0){
              continue;
            }

            if(reg.getIdMedico() == idMedico){
                reg.mostrar();
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << "No se encontraron turnos para este medico." << endl;
        }
    }

    void TurnoManager::listadoFiltradoPaciente(){
        string dniPaciente;
        bool valido, encontrado;

        int cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay turnos cargados." << endl;
            return;
        }

        do{
            cout << "Ingrese el DNI del paciente: ";
            dniPaciente = cargarCadena();

            valido = soloDigitos(dniPaciente);
            if(!valido){
                cout << "DNI invalido." << endl;
            }
        }while(!valido);

        encontrado = false;
        Turno reg;

        cout << " Turnos del paciente con el DNI: " << dniPaciente << endl;
        cout << "--------------------------------------" << endl;

        for(int i = 0; i < cantidad; i++){
            reg = _repo.leer(i);

            if(reg.getEstado() == 0){
              continue;
            }

            if(reg.getDniPaciente() == dniPaciente){
                reg.mostrar();
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << "No se encontraron turnos para este paciente." << endl;
        }
    }

    void TurnoManager::listadoFiltradoEstado(){
        int estado;

        cout << "Estados disponibles:" << endl;
        cout << "0 - cancelado" << endl;
        cout << "1 - pendiente" << endl;
        cout << "2 - atendido" << endl;

        estado = leerEntero("Ingrese el estado: ");


        while(estado < 0 || estado > 2){
            cout << "Estado invalido. Intente nuevamente." << endl;
            estado = leerEntero("Ingrese el estado: ");
        }

        int cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay turnos cargados." << endl;
            return;
        }

        bool encontrado = false;

        for(int i = 0; i < cantidad; i++){
            Turno registro = _repo.leer(i);
            if(registro.getEstado() == estado){
                registro.mostrar();
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << "No se encontraron turnos con ese estado." << endl;
        }
    }

    void TurnoManager::consultarFecha(){
        Fecha fecha;
        Turno registro;
        int cantidad;
        bool encontrado = false;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        cout << "Ingrese la fecha del turno que desea consultar: ";
        fecha.cargar();

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(fecha == registro.getFechaAtencion() && registro.getEstado() != 0){
                registro.mostrar();
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << "No se encontro ningun turno con esa fecha." << endl;
        }
    }

    void TurnoManager::consultarMedico(){
        int idMedico;
        Turno registro;
        int cantidad;
        bool encontrado = false;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        do{
            idMedico = leerEntero("Ingrese el ID del medico que desea consultar: ");
            if(idMedico <= 0){
                cout << "ID invalido." << endl;
            }

        }while(idMedico <= 0);

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(idMedico == registro.getIdMedico() && registro.getEstado() != 0){
                registro.mostrar();
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << "No se encontro ningun medico con ese ID." << endl;
        }
    }

    void TurnoManager::consultarPaciente(){
        bool valido;
        string dni;
        Turno registro;
        int cantidad;
        bool encontrado = false;

        cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros cargados." << endl;
            return;
        }

        do{
            cout << "Ingrese el DNI del paciente que desea consultar: ";
            dni = cargarCadena();

            valido = soloDigitos(dni);

            if(!valido){
                cout << "DNI invalido." << endl;
            }
        }while(!valido);

        for(int i=0; i<cantidad; i++){
            registro = _repo.leer(i);

            if(dni == registro.getDniPaciente() && registro.getEstado() != 0){
                registro.mostrar();
                encontrado = true;

            }
        }

        if(!encontrado){
            cout << "No se encontro ningun paciente con ese DNI." << endl;
        }
    }

    void TurnoManager::consultarEstado() {
        int estado;

        cout << "Estados disponibles:" << endl;
        cout << "0 - cancelado" << endl;
        cout << "1 - pendiente" << endl;
        cout << "2 - atendido" << endl;

        estado = leerEntero("Ingrese el estado a consultar: ");


        while(estado < 0 || estado > 2){
            cout << "Estado invalido. Intente nuevamente." << endl;
            estado = leerEntero("Ingrese el estado a consultar: ");
        }

        int cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay turnos cargados." << endl;
            return;
        }

        bool encontrado = false;

        for(int i = 0; i < cantidad; i++){
            Turno registro = _repo.leer(i);
            if(registro.getEstado() == estado){
                registro.mostrar();
                encontrado = true;
            }
        }

        if(!encontrado){
            cout << "No se encontraron turnos con ese estado." << endl;
        }
    }

    void TurnoManager::marcarTurnoAtendido(){

        int id;
        cout << "Ingrese el ID del turno atendido: ";
        cin >> id;

        int cantidad = _repo.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros en el archivo." << endl;
            return;
        }

        Turno reg;
        int pos = -1;

        for (int i = 0; i < cantidad; i++) {
            reg = _repo.leer(i);
            if (reg.getID() == id) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "No se encontro el turno." << endl;
            return;
        }

        if (reg.getEstado() != 1) {
            cout << "Solo se pueden marcar turnos pendientes." << endl;
            return;
        }

        reg.setEstado(2);
        _repo.modificar(pos, reg);

        // Liberar consultorio
        _repoConsultorio.liberarConsultorio(reg.getNumeroConsultorio());

        cout << "Turno atendido y consultorio liberado." << endl;
    }


#include <iostream>
#include "HistoriaClinicaManager.h"
#include "funcionesGlobales.h"

using namespace std;

HistoriaClinicaManager::HistoriaClinicaManager(){
}

void HistoriaClinicaManager::cargar()
{
    bool valido, existe;
    int id;
    string dniPaciente;
    string dniMedico;
    string diagnostico;
    string observaciones;
    string tratamiento;
    int idObraSocial;
    Fecha fecha;

    id = _repo.getNuevoID();

    do{
    existe = true;
    cout << "DNI del paciente: ";
    dniPaciente = cargarCadena();

    valido = soloDigitos(dniPaciente);

    if(dniPaciente.size() < 7 || dniPaciente.size() > 11){
        valido = false;
    }

    if(!valido){
        cout << "DNI invalido." << endl;
    }

    if(!_repoPaciente.existeDNI(dniPaciente)){
        cout << "No hay ningun paciente con este DNI." << endl;
        existe = false;
    }

    }while(!valido || !existe);

    do{
    existe = true;
    cout << "DNI del medico: ";
    dniMedico = cargarCadena();

    valido = soloDigitos(dniMedico);

    if(dniMedico.size() < 7 || dniMedico.size() > 11){
        valido = false;
    }

    if(!valido){
        cout << "DNI invalido." << endl;
    }

    if(!_repoMedico.existeDNI(dniMedico)){
        cout << "No hay ningun medico con ese DNI." << endl;
        existe = false;
    }

    }while(!valido || !existe);

    cout << "Fecha de Inicio: ";
    fecha.cargar();

    cout << "Diagnostico: ";
    diagnostico = cargarCadena();

    cout << "Observaciones: ";
    observaciones = cargarCadena();

    cout << "Tratamiento: ";
    tratamiento = cargarCadena();

    do{
        existe = true;
        idObraSocial = leerEntero( "Codigo Obra Social: ");
        if(idObraSocial <= 0){
            cout << "ID invalido." << endl;
        }

        if(!_repoObraSocial.existeID(idObraSocial)){
            cout << "No hay ninguna obra social con ese ID." << endl;
            existe = false;
        }
    }while(idObraSocial <= 0 || !existe);


    if(_repo.guardar(HistoriaClinica(id,dniPaciente,dniMedico,fecha,diagnostico,observaciones,tratamiento,idObraSocial,true)))
    {
         cout << "La Historia Clinica se guardo correctamente." << endl;
    }else{
        cout << "Hubo un error al intentar guardar la Historia Clinica." << endl;
    }
}


void HistoriaClinicaManager::eliminarHistoriaClinica()
{
    string dni;
    bool valido;
    do{
        cout << "Ingrese el DNI del paciente a eliminar: ";
        dni = cargarCadena();

        valido = soloDigitos(dni);
        if(!valido){
            cout << "DNI invalido." << endl;
        }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dni);

    if (pos == -1) {
        cout << "No se encontró una historia clínica con ese DNI." << endl;
        return;
    }

    HistoriaClinica historia = _repo.leer(pos);

    historia.setEstado(false);


    if (_repo.modificar(pos, historia)) {
        cout << "Historia Clinica eliminada correctamente." << endl;
    }
    else {
        cout << "Error al eliminar la historia clinica." << endl;
    }
}


void HistoriaClinicaManager::modificarDiagnostico()
{
    string dniBuscado;
    string nuevoDiagnostico;
    bool valido;

    do{
        cout << "Ingrese el DNI del paciente: ";
        dniBuscado = cargarCadena();

        valido = soloDigitos(dniBuscado);
        if(!valido){
            cout << "DNI invalido." << endl;
        }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }


    HistoriaClinica historia = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    historia.mostrar();

    cout << "Ingrese nuevo diagnostico: ";
    nuevoDiagnostico = cargarCadena();

    historia.setDiagnostico(nuevoDiagnostico);


    if (_repo.modificar(pos, historia)) {
        cout << "Diagnostico modificado correctamente." << endl;
    } else {
        cout << "Error al modificar el diagnostico." << endl;
    }
}

void HistoriaClinicaManager::modificarObservaciones()
{
    string dniBuscado;
    string nuevasObservaciones;
    bool valido;

    do{
        cout << "Ingrese el DNI del paciente: ";
        dniBuscado = cargarCadena();

        valido = soloDigitos(dniBuscado);
        if(!valido){
            cout << "DNI invalido." << endl;
        }

    }while(!valido);


    int pos = _repo.buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI." << endl;
        return;
    }


    HistoriaClinica historia = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    historia.mostrar();


    cout << "Ingrese las nuevas observaciones: "; //sobreescribe las observaciones
    nuevasObservaciones = cargarCadena();

    historia.setObservaciones(nuevasObservaciones);


    if (_repo.modificar(pos, historia)) {
        cout << "Observaciones actualizadas correctamente." << endl;
    } else {
        cout << "Error al actualizar las observaciones." << endl;
    }
}

void HistoriaClinicaManager::modificarTratamiento()
{
    string dniBuscado;
    string nuevoTratamiento;
    bool valido;

     do{
        cout << "Ingrese el DNI del paciente: ";
        dniBuscado = cargarCadena();

        valido = soloDigitos(dniBuscado);
        if(!valido){
            cout << "DNI invalido." << endl;
        }

    }while(!valido);


    int pos = _repo.buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI." << endl;
        return;
    }

    HistoriaClinica historia = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    historia.mostrar();

    cout << "Ingrese nuevo tratamiento: ";
    nuevoTratamiento = cargarCadena();

    historia.setTratamiento(nuevoTratamiento);


    if (_repo.modificar(pos, historia)) {
        cout << "Tratamiento modificado correctamente.";
    } else {
        cout << "Error al modificar el tratamiento.";
    }
}

void HistoriaClinicaManager::consultarDniPaciente()
{
    string dniBuscado;
    bool valido;

      do{
        cout << "Ingrese el DNI del paciente: ";
        dniBuscado = cargarCadena();

        valido = soloDigitos(dniBuscado);
        if(!valido){
            cout << "DNI invalido." << endl;
        }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI." << endl;
        return;
    }

    HistoriaClinica reg = _repo.leer(pos);

    cout << "--- HISTORIA CLINICA ENCONTRADA ---" << endl;
    reg.mostrar();
}

void HistoriaClinicaManager::consultarFechaHC()
{
    Fecha fecha;

    cout << "INGRESE LA FECHA DE LA HISTORIA CLINICA A CONSULTAR: " << endl;
    fecha.cargar();

    int cantidad = _repo.getCantidadRegistro();
    bool encontrado = false;


    for (int i = 0; i < cantidad; i++) {
        HistoriaClinica reg = _repo.leer(i);

        if (reg.getEstado()) {

            Fecha f = reg.getFecha();
            if (f.getDia() == fecha.getDia() &&
                f.getMes() == fecha.getMes() &&
                f.getAnio() == fecha.getAnio())
            {
                if (!encontrado) {
                    cout << "--- PACIENTES CON MISMA FECHA DE HISTORIA CLINICA ---" << endl;
                }
                reg.mostrar();
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontró ninguna historia clínica con esa fecha." << endl;
    }
}

void HistoriaClinicaManager::consultarDiagnostico()
{
    string diagnosticoBuscado;

    int cantidad = _repo.getCantidadRegistro();
    if(cantidad == 0){
        cout << "No hay registros en el archivo." << endl;
        return;
    }

    cout << "INGRESE DIAGNOSTICO A BUSCAR: ";
    diagnosticoBuscado = cargarCadena();


    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        HistoriaClinica reg = _repo.leer(i);

        if (reg.getEstado()) {
            if (reg.getDiagnostico() == diagnosticoBuscado) {
                if (!encontrado) {
                    cout << "--- HISTORIAS CLINICAS CON MISMO DIAGNOSTICO ---" << endl;
                }
                reg.mostrar();
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron pacientes con ese mismo diagnostico." << endl;
    }
}

#include <iostream>
#include "HistoriaClinicaManager.h"
#include "funcionesGlobales.h"

using namespace std;

HistoriaClinicaManager::HistoriaClinicaManager(){
}

void HistoriaClinicaManager::cargar()
{
    bool valido;
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
    cout << "DNI del paciente: ";
    dniPaciente = cargarCadena();

    valido = soloDigitos(dniPaciente);
    if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    do{
    cout << "DNI del medico: ";
    dniMedico = cargarCadena();

    valido = soloDigitos(dniMedico);
    if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    cout << "Fecha de Inicio: ";
    fecha.cargar();

    cout << "Diagnostico: ";
    diagnostico = cargarCadena();

    cout << "Observaciones: ";
    observaciones = cargarCadena();

    cout << "Tratamiento: ";
    tratamiento = cargarCadena();

    do{
        idObraSocial = leerEntero( "Codigo Obra Social: ");
        if(idObraSocial <= 0){
            cout << "ID invalido." << endl;
        }
    }while(idObraSocial <= 0);


    if(_repo.guardar(HistoriaClinica(id,dniPaciente,dniMedico,fecha,diagnostico,observaciones,tratamiento,idObraSocial,true)))
    {
         cout << "La Historia Clinica se guardo correctamente." << endl;
    }else{
        cout << "Hubo un error al intentar guardar la Historia Clinica." << endl;
    }
}

int HistoriaClinicaManager::buscarPosPorDni(const std::string &dniBuscado) {
    int cantidad = _repo.getCantidadRegistro();
    if(cantidad == 0){
        return -1;
    }

    for (int i = 0; i < cantidad; i++) {
        HistoriaClinica reg = _repo.leer(i);

        if (reg.getEstado() && reg.getDniPaciente() == dniBuscado) {
            return i;
        }
    }

    return -1;  // no encontrado
}

void HistoriaClinicaManager::eliminarHistoriaClinica()
{
    string dni;
    bool valido;
    do{
        cout << "Ingrese el DNI del paciente a eliminar: ";
        cin >> dni;

        valido = soloDigitos(dni);
        if(!valido){
            cout << "DNI invalido." << endl;
        }

    }while(!valido);

    int pos = buscarPosPorDni(dni);

    if (pos == -1) {
        cout << "No se encontró una historia clínica con ese DNI.";
        return;
    }

    HistoriaClinica historia = _repo.leer(pos);

    cout << "Historia clinica encontrada: ";
    historia.mostrar();


    char confirmar;
    cout << "¿Desea eliminar este paciente? (S/N): ";
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 'N') {
        cout << "Operación cancelada.";
        return;
    }


    historia.setEstado(false);


    if (_repo.modificar(pos, historia)) {
        cout << "Historia Clinica eliminada correctamente.";
    }
    else {
        cout << "Error al eliminar la historia clinica.";
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

    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }


    HistoriaClinica historia = _repo.leer(pos);

    cout << "Paciente encontrado: ";
    historia.mostrar();

    cout << "Ingrese nuevo diagnostico: ";
    nuevoDiagnostico = cargarCadena();

    historia.setDiagnostico(nuevoDiagnostico);


    if (_repo.modificar(pos, historia)) {
        cout << "Diagnostico modificado correctamente.";
    } else {
        cout << "Error al modificar el diagnostico.";
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


    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }


    HistoriaClinica historia = _repo.leer(pos);

    cout << "Paciente encontrado: ";
    historia.mostrar();


    cout << "Ingrese las nuevas observaciones: "; //sobreescribe las observaciones
    nuevasObservaciones = cargarCadena();

    historia.setObservaciones(nuevasObservaciones);


    if (_repo.modificar(pos, historia)) {
        cout << "Observaciones actualizadas correctamente.";
    } else {
        cout << "Error al actualizar las observaciones.";
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


    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }

    HistoriaClinica historia = _repo.leer(pos);

    cout << "Paciente encontrado: ";
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

    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }

    HistoriaClinica reg = _repo.leer(pos);

    cout << "--- HISTORIA CLINICA ENCONTRADA ---";
    reg.mostrar();
}

void HistoriaClinicaManager::consultarFechaHC()
{
    Fecha fecha;

    cout << "INGRESE LA FECHA DE LA HISTORIA CLINICA A CONSULTAR: ";
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
        cout << "No se encontró ninguna historia clínica con esa fecha.";
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
    cin >> diagnosticoBuscado;


    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        HistoriaClinica reg = _repo.leer(i);

        if (reg.getEstado()) {
            if (reg.getDiagnostico() == diagnosticoBuscado) {
                if (!encontrado) {
                    cout << "--- PACIENTES CON MISMO DIAGNOSTICO ---";
                }
                reg.mostrar();
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron pacientes con ese mismo diagnostico.";
    }
}

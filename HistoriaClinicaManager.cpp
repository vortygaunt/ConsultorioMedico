#include <iostream>
#include "HistoriaClinicaManager.h"

using namespace std;

historiaClinicaManager::historiaClinicaManager(){
}
std::string historiaClinicaManager::cargarCadena()
{
  std::string texto;

  if(std::cin.peek() == '\n')
  {
    std::cin.ignore();
  }

  std::getline(std::cin, texto);

  return texto;
}

void historiaClinicaManager::cargar()
{
    int id;
    string dniPaciente;
    string dniMedico;
    string diagnostico;
    string observaciones;
    string tratamiento;
    int idObraSocial;
    Fecha fecha;

    id = _repo.getNuevoID();

    cout << "DNI DEL PACIENTE: ";
    dniPaciente = cargarCadena();

    cout << "DNI DEL MEDICO ";
    dniMedico = cargarCadena();

    cout << "Fecha de Inicio: ";
    fecha.cargar();

    cout << "Diagnostico: ";
    diagnostico = cargarCadena();

    cout << "Observaciones: ";
    observaciones = cargarCadena();

    cout << "Tratamiento: ";
    tratamiento = cargarCadena();

    cout << "Codigo Obra Social: ";
    cin >> idObraSocial;
    cin.ignore();



    if(_repo.guardar(HistoriaClinica(id,dniPaciente,dniMedico,fecha,diagnostico,observaciones,tratamiento,idObraSocial,true)))
    {
         cout << "La Historia Clinica se guardo correctamente." << endl;
    }else{
        cout << "Hubo un error al intentar guardar la Historia Clinica." << endl;
    }
}

int historiaClinicaManager::buscarPosPorDni(const std::string &dniBuscado) {
    int cantidad = _repo.getCantidadRegistro();

    for (int i = 0; i < cantidad; i++) {
        HistoriaClinica reg = _repo.leer(i);

        if (reg.getEstado() && reg.getDniPaciente() == dniBuscado) {
            return i;
        }
    }

    return -1;  // no encontrado
}

void historiaClinicaManager::eliminarHistoriaClinica()
{
    string dni;
    cout << "INGRESE DNI DEL PACIENTE A ELIMINAR: ";
    cin >> dni;

    int pos = buscarPosPorDni(dni);

    if (pos == -1) {
        cout << "No se encontró una historia clínica con ese DNI.";
        return;
    }

    HistoriaClinica historia = _repo.leer(pos);

    cout << "HISTORIA CLINICA ENCONTRADA: ";
    historia.mostrar();


    char confirmar;
    cout << "¿DESEA ELIMINAR ESTE PACIENTE? (S/N): ";
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 's') {
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


void historiaClinicaManager::modificarDiagnostico()
{
    string dniBuscado;
    cout << "INGRESE DNI DEL PACIENTE: ";
    cin >> dniBuscado;

    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }


    HistoriaClinica historia = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    historia.mostrar();


    string nuevoDiagnostico;
    cout << "INGRESE NUEVO DIAGNOSTICO: ";
    cin >> nuevoDiagnostico;

    historia.setDiagnostico(nuevoDiagnostico);


    if (_repo.modificar(pos, historia)) {
        cout << "Diagnostico modificado correctamente.";
    } else {
        cout << "Error al modificar el diagnostico.";
    }
}

void historiaClinicaManager::modificarObservaciones()
{
    string dniBuscado;
    cout << "INGRESE DNI DEL PACIENTE: ";
    cin >> dniBuscado;


    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }


    HistoriaClinica historia = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    historia.mostrar();


    string nuevasObservaciones;
    cout << "INGRESE NUEVAS OBSERVACIONES: "; //sobreescribe las observaciones
    nuevasObservaciones = cargarCadena();

    historia.setObservaciones(nuevasObservaciones);


    if (_repo.modificar(pos, historia)) {
        cout << "Observaciones actualizadas correctamente.";
    } else {
        cout << "Error al actualizar las observaciones.";
    }
}

void historiaClinicaManager::modificarTratamiento()
{
    string dniBuscado;
    cout << "INGRESE DNI DEL PACIENTE: ";
    cin >> dniBuscado;


    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }

    HistoriaClinica historia = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    historia.mostrar();


    string nuevoTratamiento;
    cout << "INGRESE NUEVO TRATAMIENTO: ";
    cin >> nuevoTratamiento;

    historia.setTratamiento(nuevoTratamiento);


    if (_repo.modificar(pos, historia)) {
        cout << "Tratamiento modificado correctamente.";
    } else {
        cout << "Error al modificar el tratamiento.";
    }
}

void historiaClinicaManager::consultarDniPaciente()
{
    string dniBuscado;
    cout << "INGRESE DNI: ";
    cin >> dniBuscado;

    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontró historia clínica para este DNI.";
        return;
    }

    HistoriaClinica reg = _repo.leer(pos);

    cout << "--- HISTORIA CLINICA ENCONTRADA ---";
    reg.mostrar();
}

void historiaClinicaManager::consultarFechaHC()
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

void historiaClinicaManager::consultarDiagnostico()
{
    string diagnosticoBuscado;
    cout << "INGRESE DIAGNOSTICO A BUSCAR: ";
    cin >> diagnosticoBuscado;

    int cantidad = _repo.getCantidadRegistro();
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

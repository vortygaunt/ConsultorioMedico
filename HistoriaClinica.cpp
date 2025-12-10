#include <iostream>
#include "historiaClinica.h"
#include "Fecha.h"

using namespace std;

HistoriaClinica::HistoriaClinica(): _id(0), _fecha(), _idObraSocial(0), _estado (false)
{
    _dniPaciente[0] = '\0';
    _dniMedico[0] = '\0';
    _diagnostico[0] = '\0';
    _observaciones[0] = '\0';
    _tratamiento[0] = '\0';
}

HistoriaClinica::HistoriaClinica(int id, string dniPaciente, string dniMedico, Fecha fecha, string diagnostico, string observaciones, string tratamiento, int idObraSocial,bool estado)
{
    setId(id);
    setDniPaciente(dniPaciente);
    setDniMedico(dniMedico);
    setFecha(fecha);
    setDiagnostico(diagnostico);
    setObservaciones(observaciones);
    setTratamiento(tratamiento);
    setIdObraSocial(idObraSocial);
    setEstado(estado);
}

void HistoriaClinica::setId(int id){
    _id = id;
}

void HistoriaClinica::setDniPaciente(string dniP){
    strncpy(_dniPaciente, dniP.c_str(), 11);
    _dniPaciente[11] = '\0';
}

void HistoriaClinica::setDniMedico(string dniM){
    strncpy(_dniMedico, dniM.c_str(), 11);
    _dniMedico[11] = '\0';
}

void HistoriaClinica::setFecha(Fecha fecha){
    _fecha = fecha;
}

void HistoriaClinica::setDiagnostico(string diagnostico){
    strncpy(_diagnostico, diagnostico.c_str(), 99);
    _diagnostico[99] = '\0';
}

void HistoriaClinica::setObservaciones(string observaciones){
    strncpy(_observaciones, observaciones.c_str(), 99);
    _observaciones[99] = '\0';
}

void HistoriaClinica::setTratamiento(string tratamiento){
    strncpy(_tratamiento, tratamiento.c_str(), 99);
    _tratamiento[99] = '\0';
}

void HistoriaClinica::setIdObraSocial(int idObra){
    if(idObra > 0){
        _idObraSocial = idObra;
    }
}

void HistoriaClinica::setEstado(bool estado){
    _estado = estado;
}


int HistoriaClinica::getId(){
    return _id;
}

string HistoriaClinica::getDniPaciente(){
    return string(_dniPaciente);
}

string HistoriaClinica::getDniMedico(){
    return string(_dniMedico);
}

Fecha HistoriaClinica::getFecha(){
    return _fecha;
}

string HistoriaClinica::getDiagnostico(){
    return string(_diagnostico);
}

string HistoriaClinica::getObservaciones(){
    return string(_observaciones);
}

string HistoriaClinica::getTratamiento(){
    return string(_tratamiento);
}

int HistoriaClinica::getIdObraSocial(){
    return _idObraSocial;
}

bool HistoriaClinica::getEstado()
{
    return _estado;
}

void HistoriaClinica::mostrar(){
    cout << "----------------------------------------" << endl;
    cout << "ID: " << _id << endl;
    cout << "DNI PACIENTE: " << _dniPaciente << endl;
    cout << "DNI MEDICO: " << _dniMedico << endl;
    cout << "FECHA: ";
    _fecha.mostrar();
    cout << "DIAGNOSTICO: " << _diagnostico << endl;
    cout << "OBSERVACIONES: " << _observaciones << endl;
    cout << "TRATAMIENTO: " << _tratamiento << endl;
    cout << "ID OBRA SOCIAL: " << _idObraSocial << endl;
    cout << "----------------------------------------" << endl;
}

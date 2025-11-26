#include <iostream>
#include <cstring>
#include "Turno.h"

using namespace std;

Turno::Turno()
:_id(0), _idMedico(0), _fechaAtencion(), _horaAtencion(), _importeConsulta(0), _numeroConsultorio(0), _estado(1){
    strcpy(_dniPaciente, "");

}

Turno::Turno(int id, string dniPaciente, int IdMedico, Fecha fechaAtencion, Hora horaAtencion, float importeConsulta, int numeroConsultorio, int estado){
    setID(id);
    setDniPaciente(dniPaciente);
    setIdMedico(IdMedico);
    setFechaAtencion(fechaAtencion);
    setHoraAtencion(horaAtencion);
    setImporteConsulta(importeConsulta);
    setNumeroConsultorio(numeroConsultorio);
    setEstado(estado);
}

void Turno::setID(int id){
    if(id > 0){
        _id = id;
    }
}

void Turno::setDniPaciente(string dniPaciente){
    strncpy(_dniPaciente, dniPaciente.c_str(), 11);
    _dniPaciente[11] = '\0';
}

void Turno::setIdMedico(int idMedico){
    if(idMedico > 0){
        _idMedico = idMedico;
    }
}

void Turno::setFechaAtencion(Fecha fechaAtencion){
    _fechaAtencion = fechaAtencion;
}

void Turno::setHoraAtencion(Hora horaAtencion){
    _horaAtencion = horaAtencion;
}

void Turno::setImporteConsulta(float importeConsulta){
    if(importeConsulta >= 0){
        _importeConsulta = importeConsulta;
    }
}

void Turno::setNumeroConsultorio(int numeroConsultorio){
    if(numeroConsultorio > 0){
        _numeroConsultorio = numeroConsultorio;
    }
}

void Turno::setEstado(int estado){
    if(estado == 0 || estado == 1 || estado == 2){
        _estado = estado;
    }
}

int Turno::getID(){
    return _id;
}

string Turno::getDniPaciente(){
    return string (_dniPaciente);
}

int Turno::getIdMedico(){
    return _idMedico;
}

Fecha Turno::getFechaAtencion(){
    return _fechaAtencion;
}

Hora Turno::getHoraAtencion(){
    return _horaAtencion;
}

float Turno::getImporteConsulta(){
    return _importeConsulta;
}

int Turno::getNumeroConsultorio(){
    return _numeroConsultorio;
}

int Turno::getEstado(){
    return _estado;
}

void Turno::mostrar(){
    string textoEstado;
    cout << "ID: " << _id << endl;
    cout << "DNI Paciente: " << _dniPaciente << endl;
    cout << "ID Medico: " << _idMedico << endl;
    cout << "Fecha de atencion: ";
    _fechaAtencion.mostrar();
    cout << "Hora de atencion: ";
    _horaAtencion.mostrar();
    cout << "Importe de la consulta: $" << _importeConsulta << endl;
    cout << "Numero de consultorio: " << _numeroConsultorio << endl;
    switch(_estado){
    case 0: textoEstado = "Cancelado";
        break;
    case 1: textoEstado = "Pendiente";
        break;
    case 2: textoEstado = "Atendido";
        break;
    }
    cout << "Estado: " << _estado << endl;
    cout << "------------------------------------------------------" << endl;
}

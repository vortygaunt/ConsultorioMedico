#include <iostream>
#include <cstring>
#include "Medico.h"

using namespace std;

    Medico::Medico()
    :_idMedico(0), _codigoEspecialidad(0), _fechaInicio(), _estado(false){
        strcpy(_dniMedico, "");
        strcpy(_nombreMedico, "");
        strcpy(_apellidoMedico, "");
        strcpy(_telefonoMedico, "");
        strcpy(_emailMedico, "");
        strcpy(_matricula, "");
    }

    Medico::Medico(int idMedico, string dniMedico, string nombreMedico, string apellidoMedico, string telefonoMedico, string emailMedico, string matricula, int codigoEspecialidad, Fecha fechaInicio, bool estado){
        setIdMedico(idMedico);
        setDniMedico(dniMedico);
        setNombreMedico(nombreMedico);
        setApellidoMedico(apellidoMedico);
        setTelefonoMedico(telefonoMedico);
        setEmailMedico(emailMedico);
        setMatricula(matricula);
        setCodigoEspecialidad(codigoEspecialidad);
        setFechaInicio(fechaInicio);
        setEstado(estado);
    }

    void Medico::setIdMedico(int idMedico){
        if(idMedico > 0){
            _idMedico = idMedico;
        }
    }
    void Medico::setDniMedico(string dniMedico){
        strncpy(_dniMedico, dniMedico.c_str(), 11);
    }
    void Medico::setNombreMedico(string nombreMedico){
        strncpy(_nombreMedico, nombreMedico.c_str(), 29);
    }
    void Medico::setApellidoMedico(string apellidoMedico){
        strncpy(_apellidoMedico, apellidoMedico.c_str(), 29);
    }
    void Medico::setTelefonoMedico(string telefonoMedico){
        strncpy(_telefonoMedico, telefonoMedico.c_str(), 19);
    }
    void Medico::setEmailMedico(string emailMedico){
        strncpy(_emailMedico, emailMedico.c_str(), 39);
    }
    void Medico::setMatricula(string matricula){
        strncpy(_matricula, matricula.c_str(), 14);
    }
    void Medico::setCodigoEspecialidad(int codigoEspecialidad){
         if(codigoEspecialidad > 0){
            _codigoEspecialidad = codigoEspecialidad;
        }
    }
    void Medico::setFechaInicio(Fecha fechaInicio){
        _fechaInicio = fechaInicio;
    }
    void Medico::setEstado(bool estado){
        _estado = estado;
    }

    int Medico::getIdMedico(){
        return _idMedico;
    }
    string Medico::getDniMedico(){
        return string(_dniMedico);
    }
    string Medico::getNombreMedico(){
        return string(_nombreMedico);
    }
    string Medico::getApellidoMedico(){
        return string(_apellidoMedico);
    }
    string Medico::getTelefonoMedico(){
        return string(_telefonoMedico);
    }
    string Medico::getEmailMedico(){
        return string(_emailMedico);
    }
    string Medico::getMatricula(){
        return string(_matricula);
    }
    int Medico::getCodigoEspecialidad(){
        return _codigoEspecialidad;
    }
    Fecha Medico::getFechaInicio(){
        return _fechaInicio;
    }
    bool Medico::getEstado(){
        return _estado;
    }

    void Medico::mostrar(){
        cout << "ID: " << _idMedico << endl;
        cout << "DNI: " << _dniMedico << endl;
        cout << "Nombre: " << _nombreMedico << endl;
        cout << "Apellido: " << _apellidoMedico << endl;
        cout << "Telefono: " << _telefonoMedico << endl;
        cout << "Email: " << _emailMedico << endl;
        cout << "Matricula: " << _matricula << endl;
        cout << "Codigo de Especialidad: " << _codigoEspecialidad << endl;
        cout << "Fecha de inicio: ";
        _fechaInicio.mostrar();
    }

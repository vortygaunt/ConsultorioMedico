#include <iostream>
#include <cstring>
#include "Paciente.h"

using namespace std;

Paciente::Paciente(): _codigoObraSocial(0), _fechaNacimiento(), _direccion(), _estado(false)
{
    strcpy(_dniPaciente, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");

}

Paciente::Paciente(string dniPaciente, string nombre, string apellido, string telefono, PacienteDireccion direccion, string email, int codObraSocial, Fecha fecha, bool estado)
{
    setDniPaciente(dniPaciente);
    setNombrePaciente(nombre);
    setApellidoPaciente(apellido);
    setTelefonoPaciente(telefono);
    setDireccionPaciente(direccion);
    setEmailPaciente(email);
    setCodigoObraSocialPaciente(codObraSocial);
    setFechaNacimientoPaciente(fecha);
    setEstadoPaciente(estado);
}

void Paciente::setDniPaciente(const string& dni) {

    strncpy(_dniPaciente, dni.c_str(), 11);
    _dniPaciente[11] = '\0';
}

void Paciente::setNombrePaciente(const string& nombre) {
    strncpy(_nombre, nombre.c_str(), 29);
    _nombre[29] = '\0';
}

void Paciente::setApellidoPaciente(const string& apellido) {
    strncpy(_apellido, apellido.c_str(), 29);
    _apellido[29] = '\0';
}

void Paciente::setTelefonoPaciente(const string& telefono) {
    strncpy(_telefono, telefono.c_str(),19);
    _telefono[19] = '\0';
}

void Paciente::setDireccionPaciente(PacienteDireccion& direccion) {
    _direccion = direccion;
}

void Paciente::setEmailPaciente(const string& email) {
    strncpy(_email, email.c_str(), 39);
     _email[39] = '\0';
}

void Paciente::setCodigoObraSocialPaciente(int codigo) {
    if(codigo > 0){
        _codigoObraSocial = codigo;
    }
}

void Paciente::setFechaNacimientoPaciente(Fecha& fecha) {
    _fechaNacimiento = fecha;
}

void Paciente::setEstadoPaciente(bool estado) {
    _estado = estado;
}


std::string Paciente::getDniPaciente() {
    return std::string(_dniPaciente);
}
std::string Paciente::getNombrePaciente() {
    return std::string(_nombre);
}

std::string Paciente::getApellidoPaciente() {
    return std::string(_apellido);
}
std::string Paciente::getTelefonoPaciente() {
    return std::string(_telefono);
}
PacienteDireccion Paciente::getDireccionPaciente(){
    return _direccion;
}

std::string Paciente::getEmailPaciente() {
    return std::string(_email);
}
int Paciente::getCodigoObraSocialPaciente() {
    return _codigoObraSocial;
}
Fecha Paciente::getFechaNacimientoPaciente() {
    return _fechaNacimiento;
}
bool Paciente::getEstadoPaciente() {
    return _estado;
}


void Paciente::mostrar() {
    cout << "----------------------------------------"<<endl;
    cout << "DNI: " << _dniPaciente << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Telefono: " << _telefono << endl;
    _direccion.mostrar();
    cout << "Email: " << _email << endl;
    cout << "Codigo Obra Social: " << _codigoObraSocial << endl;
    cout << "Fecha de nacimiento: ";
    _fechaNacimiento.mostrar();

}


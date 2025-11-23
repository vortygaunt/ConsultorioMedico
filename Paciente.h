#pragma once
#include <string>
#include "Fecha.h"
#include "PacienteDireccion.h"

class Paciente {
private:
    char _dniPaciente[12];
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email[40];
    int _codigoObraSocial;
    Fecha _fechaNacimiento;
    PacienteDireccion _direccion;
    bool _estado;

public:

    Paciente();
    Paciente(std::string dniPaciente, std::string nombre, std::string apellido, std::string telefono, PacienteDireccion direccion, std::string email, int codObraSocial, Fecha fecha, bool estado = true);

    void setDniPaciente(const std::string& dni);
    void setNombrePaciente(const std::string& nombre);
    void setApellidoPaciente(const std::string& apellido);
    void setTelefonoPaciente(const std::string& telefono);
    void setDireccionPaciente(PacienteDireccion& direccion);
    void setEmailPaciente(const std::string& email);
    void setCodigoObraSocialPaciente(int codigo);
    void setFechaNacimientoPaciente( Fecha& fecha);
    void setEstadoPaciente(bool estado);

    std::string getDniPaciente();
    std::string getNombrePaciente();
    std::string getApellidoPaciente();
    std::string getTelefonoPaciente();
    PacienteDireccion getDireccionPaciente();
    std::string getEmailPaciente();
    int getCodigoObraSocialPaciente();
    Fecha getFechaNacimientoPaciente();
    bool getEstadoPaciente();

    void mostrar();

};


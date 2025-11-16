#pragma once
#include <string>
#include "Fecha.h"

class Medico{
public:
    Medico();
    Medico(int idMedico, std::string dniMedico, std::string nombreMedico, std::string apellidoMedico, std::string telefonoMedico, std::string emailMedico, std::string matricula, int codigoEspecialidad, Fecha fechaInicio, bool estado = true);

    void setIdMedico(int idMedico);
    void setDniMedico(std::string dniMedico);
    void setNombreMedico(std::string nombreMedico);
    void setApellidoMedico(std::string apellidoMedico);
    void setTelefonoMedico(std::string telefonoMedico);
    void setEmailMedico(std::string emailMedico);
    void setMatricula(std::string matricula);
    void setCodigoEspecialidad(int codigoEspecialidad);
    void setFechaInicio(Fecha fechaInicio);
    void setEstado(bool estado);

    int getIdMedico();
    std::string getDniMedico();
    std::string getNombreMedico();
    std::string getApellidoMedico();
    std::string getTelefonoMedico();
    std::string getEmailMedico();
    std::string getMatricula();
    int getCodigoEspecialidad();
    Fecha getFechaInicio();
    bool getEstado();

    void mostrar();
private:
    int _idMedico;
    char _dniMedico[12];
    char _nombreMedico[30];
    char _apellidoMedico[30];
    char _telefonoMedico[20];
    char _emailMedico[40];
    char _matricula[15];
    int _codigoEspecialidad;
    Fecha _fechaInicio;
    bool _estado;
};

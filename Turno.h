#pragma once
#include "Fecha.h"
#include "Hora.h"

class Turno{
public:
    Turno();
    Turno(int id, std::string dniPaciente, int IdMedico, Fecha fechaAtencion, Hora horaAtencion, float importeConsulta, int numeroConsultorio, int estado = 1);

    void setID(int id);
    void setDniPaciente(std::string dniPaciente);
    void setIdMedico(int IdMedico);
    void setFechaAtencion(Fecha fechaAtencion);
    void setHoraAtencion(Hora horaAtencion);
    void setImporteConsulta(float importeConsulta);
    void setNumeroConsultorio(int numeroConsultorio);
    void setEstado(int estado);

    int getID();
    std::string getDniPaciente();
    int getIdMedico();
    Fecha getFechaAtencion();
    Hora getHoraAtencion();
    float getImporteConsulta();
    int getNumeroConsultorio();
    int getEstado();

    void mostrar();

private:
    int _id;
    char _dniPaciente[12];
    int _idMedico;
    Fecha _fechaAtencion;
    Hora _horaAtencion;
    float _importeConsulta;
    int _numeroConsultorio;
    int _estado; // 0 cancelado, 1 pendiente, 2 atendido
};

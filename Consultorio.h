#pragma once

class Consultorio{
public:
    Consultorio();
    Consultorio(int numeroConsultorio, int pisoConsultorio, int codigoEspecialidad, bool ocupado, int idMedico, bool estado = true);

    void setNumeroConsultorio(int numeroConsultorio);
    void setPisoConsultorio(int pisoConsultorio);
    void setCodigoEspecialidad(int codigoEspecialidad);
    void setOcupado(bool ocupado);
    void setIdMedico(int idMedico);
    void setEstado(bool estado);

    int getNumeroConsultorio();
    int getPisoConsultorio();
    int getCodigoEspecialidad();
    bool getOcupado();
    int getIdMedico();
    bool getEstado();

    void mostrar();
private:
    int _numeroConsultorio;
    int _pisoConsultorio;
    int _codigoEspecialidad;
    bool _ocupado;
    int _idMedico;
    bool _estado;
};

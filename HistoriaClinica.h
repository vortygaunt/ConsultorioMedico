#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Fecha.h"
using namespace std;

class HistoriaClinica {
private:
    int _id;
    char _dniPaciente[12];
    char _dniMedico[12];
    Fecha _fecha;
    char _diagnostico[100];
    char _observaciones[100];
    char _tratamiento[100];
    int _idObraSocial;
    bool _estado;

public:
    HistoriaClinica();
    HistoriaClinica(int id, std::string dniPaciente, std::string dniMedico, Fecha fecha, std::string diagnostico, std::string observaciones, std::string tratamiento, int idObraSocial,bool estado = true);

    void setId(int id);
    void setDniPaciente(const std::string& dniP);
    void setDniMedico(const std::string& dniM);
    void setFecha(const Fecha& fecha);
    void setDiagnostico(const std::string& diagnostico);
    void setObservaciones(const std::string& observaciones);
    void setTratamiento(const std::string& tratamiento);
    void setIdObraSocial(int idObra);
    void setEstado(bool estado);


    int getId();
    std::string getDniPaciente();
    std::string getDniMedico();
    Fecha getFecha();
    std::string getDiagnostico();
    std::string getObservaciones();
    std::string getTratamiento();
    int getIdObraSocial();
    bool getEstado();

    void mostrar() const;
};

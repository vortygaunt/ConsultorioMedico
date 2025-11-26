#pragma once
#include "HistoriaClinicaArchivo.h"

class HistoriaClinicaManager
{
private:
    HistoriaClinicaArchivo _repo;

public:
    HistoriaClinicaManager();
    void cargar();
    void eliminarHistoriaClinica();
    int buscarPosPorDni(const std::string &dniBuscado);

    void modificarDiagnostico();
    void modificarObservaciones();
    void modificarTratamiento();


    void consultarDniPaciente();
    void consultarFechaHC();
    void consultarDiagnostico();

};

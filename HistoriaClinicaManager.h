#pragma once
#include "HistoriaClinicaArchivo.h"

class historiaClinicaManager
{
private:
    HistoriaClinicaArchivo _repo;

public:
    historiaClinicaManager();
    void cargar();
    void eliminarHistoriaClinica();
    int buscarPosPorDni(const std::string &dniBuscado);

    void modificarDiagnostico();
    void modificarObservaciones();
    void modificarTratamiento();


    void consultarDniPaciente();
    void consultarFechaHC();
    void consultarDiagnostico();


    std::string cargarCadena();
};

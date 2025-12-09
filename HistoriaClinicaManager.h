#pragma once
#include "HistoriaClinicaArchivo.h"
#include "PacienteArchivo.h"
#include "MedicoArchivo.h"
#include "ObraSocialArchivo.h"

class HistoriaClinicaManager
{
private:
    HistoriaClinicaArchivo _repo;
    PacienteArchivo _repoPaciente;
    MedicoArchivo _repoMedico;
    ObraSocialArchivo _repoObraSocial;
public:
    HistoriaClinicaManager();
    void cargar();
    void eliminarHistoriaClinica();


    void modificarDiagnostico();
    void modificarObservaciones();
    void modificarTratamiento();

    void listarPorFecha();

    void consultarDniPaciente();
    void consultarFechaHC();
    void consultarDiagnostico();

};

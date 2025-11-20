#pragma once
#include "MedicoArchivo.h"
#include "ConsultorioArchivo.h"
#include "ObraSocialArchivo.h"

class ConfiguracionManager{
public:
    void backupTurno();
    void backupMedico();
    void backupPaciente();
    void backupConsultorio();
    void backupObraSocial();
    void backupHistoriaClinica();
    void backupEspecialidades();

    void restaurarArchvioTurno();
    void restaurarArchvioMedico();
    void restaurarArchvioPaciente();
    void restaurarArchvioConsultorio();
    void restaurarArchvioObraSocial();
    void restaurarArchvioHistoriaClinica();
    void restaurarArchvioEspecialidades();

    void exportarCSVTurno();
    void exportarCSVMedico();
    void exportarCSVPaciente();
    void exportarCSVConsultorio();
    void exportarCSVObraSocial();
    void exportarCSVHistoriaClinica();
    void exportarCSVEspecialidades();
private:
    MedicoArchivo _repoMedico;
    ConsultorioArchivo _repoConsultorio;
    ObraSocialArchivo _repoObrasocial;
};

#pragma once
#include "MedicoArchivo.h"
#include "ConsultorioArchivo.h"
#include "ObraSocialArchivo.h"
#include "HistoriaClinicaArchivo.h"
#include "TurnoArchivo.h"
#include "EspecialidadArchivo.h"

class ReporteManager{
public:
    void facturacionMensualYAnual();
    void facturacionPorMedico();
    void turnosPorEspecialidad();
    void atencionPorObraSocial();
    void diagnosticosFrecuentes();
private:
    MedicoArchivo _repoMedico;
    ConsultorioArchivo _repoConsultorio;
    ObraSocialArchivo _repoObrasocial;
    HistoriaClinicaArchivo  _repoHC;
    TurnoArchivo _repoTurno;
    EspecialidadArchivo  _repoEspecialidad;
};

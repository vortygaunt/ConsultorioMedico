#pragma once
#include "MedicoArchivo.h"
#include "ConsultorioArchivo.h"
#include "ObraSocialArchivo.h"

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
};

#pragma once
#include "TurnoArchivo.h"
#include "MedicoArchivo.h"
#include "EspecialidadArchivo.h"
#include "ObraSocialArchivo.h"
#include "ConsultorioArchivo.h"

class TurnoManager{
public:
    TurnoManager();

    void cargar();
    void bajaLogica();

    void modificarFecha();
    void modificarHora();
    void modificarNumeroConsultorio();
    void modificarImporte();

    void listadoOrdenFecha();
    void listadoFiltradoMedico();
    void listadoFiltradoPaciente();
    void listadoFiltradoEstado();

    void consultarFecha();
    void consultarMedico();
    void consultarPaciente();
    void consultarEstado();

    void marcarTurnoAtendido();

private:
    TurnoArchivo _repo;
    MedicoArchivo _repoMedico;
    EspecialidadArchivo _repoEspecialidad;
    ObraSocialArchivo _repoObraSocial;
    ConsultorioArchivo _repoConsultorio;
};

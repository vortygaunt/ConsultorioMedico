#pragma once
#include "TurnoArchivo.h"

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
private:
    TurnoArchivo _repo;
};

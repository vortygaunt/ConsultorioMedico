#pragma once
#include "ConsultorioArchivo.h"
#include "MedicoArchivo.h"

class ConsultorioManager{
public:
    ConsultorioManager();

    void cargar();
    void bajaLogica();

    void listadoOrdenNumero();
    void listadoOrdenPiso();

    void consultarNumeroConsultorio();

    void modificarCodigoEspecialidad();
private:
    ConsultorioArchivo _repo;
    MedicoArchivo _repoMedico;
};

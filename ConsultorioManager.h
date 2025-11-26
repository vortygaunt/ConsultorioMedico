#pragma once
#include "ConsultorioArchivo.h"

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
};

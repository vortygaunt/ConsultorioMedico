#pragma once
#include "MedicoArchivo.h"

class MedicoManager{
public:
    MedicoManager();

    void cargar();

    void listadoOrdenApellido();
    void listadoOrdenEspecialidad();
    void listadoOrdenAntiguedad();

    void bajaLogica();

    void modificarTelefono();
    void modificarEmail();
    void modificarCodigoEspecialidad();

    void consultarDni();
    void consultarCodigoEspecialidad();
    void consultarMatricula();
    void consultarAntiguedad();
private:
    MedicoArchivo _repo;
};

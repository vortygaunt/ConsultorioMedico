#pragma once
#include "EspecialidadArchivo.h"

class EspecialidadManager{
public:
    EspecialidadManager();

    void cargar();
    void bajaLogica();

    void modificarDescripcion();

    void listadoOrdenDescripcion();

    void consultaDescripcion();
private:
    EspecialidadArchivo _repo;

};

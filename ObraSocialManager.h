#pragma once
#include "ObraSocialArchivo.h"

class ObraSocialManager{
public:
    void cargar();
    void bajaLogica();
    void listadoOrdenNombre();
    void consultarNombre();
    void modificarNombre();
    void modificarTelefono();
private:
    ObraSocialArchivo _repo;
};

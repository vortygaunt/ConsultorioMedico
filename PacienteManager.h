#pragma once
#include "PacienteArchivo.h"
#include "ObraSocialArchivo.h"

class PacienteManager{
private:
    PacienteArchivo _repo;
    ObraSocialArchivo _obraManager;

public:
    PacienteManager();
    void cargar();
    void eliminarPaciente();


    void modificarTelefono();
    void modificarDireccion();
    void modificarEmail();
    void modificarObraSocial();


    void consultarDni();
    void consultarApellidoNombre();
    void consultarObraSocial();

    void listarOrdenApellido();
    void listarFechaNacimiento();
    void listarObraSocial();

};


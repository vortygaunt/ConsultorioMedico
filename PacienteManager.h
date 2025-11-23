#pragma once
#include "PacienteArchivo.h"

class PacienteManager{
private:
    PacienteArchivo _repo;

public:
    PacienteManager();
    void cargar();
    void eliminarPaciente();
    int buscarPosPorDni(std::string& dniBuscado);

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

    std::string cargarCadena();
};

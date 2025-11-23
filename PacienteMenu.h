#pragma once
#include "PacienteManager.h"
#include "PacienteMenuListar.h"
#include "PacienteModificarMenu.h"
#include "PacienteMenuConsulta.h"


class PacientesMenu
{
private:
    int _opciones;
    PacienteManager _pacienteManager;
    PacienteMenuListar _pacientesListar;
    PacienteModificarMenu _pacienteModificar;
    PacienteMenuConsulta consultaPacientes;




public:
    PacientesMenu();
    void mostrar();
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpcion(int opcion);
};

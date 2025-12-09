#pragma once
#include "Menu.h"
#include "PacienteManager.h"
#include "PacienteMenuListar.h"
#include "PacienteModificarMenu.h"
#include "PacienteMenuConsulta.h"


class PacientesMenu: public Menu{
private:

protected:
    PacienteManager _pacienteManager;
    PacienteMenuListar _pacientesListar;
    PacienteModificarMenu _pacienteModificar;
    PacienteMenuConsulta _consultaPacientes;

    void mostrarOpciones();
    void ejecutarOpciones(int opcion);


public:
    PacientesMenu();
};

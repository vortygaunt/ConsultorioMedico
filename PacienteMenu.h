#pragma once
#include "Menu.h"
#include "PacienteManager.h"
#include "PacienteMenuListar.h"
#include "PacienteModificarMenu.h"
#include "PacienteMenuConsulta.h"


class PacientesMenu: public Menu{
private:
    PacienteManager _pacienteManager;
    PacienteMenuListar _pacientesListar;
    PacienteModificarMenu _pacienteModificar;
    PacienteMenuConsulta _consultaPacientes;




public:
    PacientesMenu();
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);
};

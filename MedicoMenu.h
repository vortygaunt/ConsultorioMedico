#pragma once
#include "MedicoManager.h"
#include "MedicoModificarMenu.h"
#include "MedicoConsultaMenu.h"
#include "MedicoListarMenu.h"

class MedicoMenu{
public:
    MedicoMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    MedicoManager _medicoManager;
    MedicoModificarMenu _medicoModificarMenu;
    MedicoConsultaMenu _medicoConsultaMenu;
    MedicoListarMenu _medicoListarMenu;
private:
    int _cantidadOpciones;

};

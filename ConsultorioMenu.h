#pragma once
#include "ConsultorioManager.h"
#include "ConsultorioListarMenu.h"

class ConsultorioMenu{
public:
    ConsultorioMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ConsultorioManager _consultorioManager;
    ConsultorioListarMenu _consultorioListarMenu;
private:
    int _cantidadOpciones;

};

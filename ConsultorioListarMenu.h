#pragma once
#include "ConsultorioManager.h"

class ConsultorioListarMenu{
public:
    ConsultorioListarMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ConsultorioManager _consultorioManager;
private:
    int _cantidadOpciones;
};

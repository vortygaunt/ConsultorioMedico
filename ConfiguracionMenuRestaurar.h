#pragma once
#include "ConfiguracionManager.h"

class ConfiguracionMenuRestaurar{
public:
    ConfiguracionMenuRestaurar();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ConfiguracionManager _configuracionManager;
private:
    int _cantidadOpciones;
};

#pragma once
#include "ConfiguracionManager.h"

class ConfiguracionMenuBackups{
public:
    ConfiguracionMenuBackups();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ConfiguracionManager _configuracionManager;
private:
    int _cantidadOpciones;
};

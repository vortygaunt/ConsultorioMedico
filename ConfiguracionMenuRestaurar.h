#pragma once
#include "Menu.h"
#include "ConfiguracionManager.h"

class ConfiguracionMenuRestaurar: public Menu{
public:
    ConfiguracionMenuRestaurar();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ConfiguracionManager _configuracionManager;
private:

};

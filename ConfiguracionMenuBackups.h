#pragma once
#include "Menu.h"
#include "ConfiguracionManager.h"

class ConfiguracionMenuBackups: public Menu{
public:
    ConfiguracionMenuBackups();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ConfiguracionManager _configuracionManager;
private:

};

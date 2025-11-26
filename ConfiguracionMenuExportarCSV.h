#pragma once
#include "Menu.h"
#include "ConfiguracionManager.h"

class ConfiguracionMenuExportarCSV: public Menu{
public:
    ConfiguracionMenuExportarCSV();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ConfiguracionManager _configuracionManager;
private:

};

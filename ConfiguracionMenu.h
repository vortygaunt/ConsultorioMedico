#pragma once
#include "Menu.h"
#include "ConfiguracionMenuBackups.h"
#include "ConfiguracionMenuRestaurar.h"
#include "ConfiguracionMenuExportarCSV.h"

class ConfiguracionMenu: public Menu{
public:
    ConfiguracionMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    ConfiguracionMenuBackups _configuracionMenuBackups;
    ConfiguracionMenuRestaurar _configuracionMenuRestaurar;
    ConfiguracionMenuExportarCSV _configuracionMenuExportarCSV;
private:

};

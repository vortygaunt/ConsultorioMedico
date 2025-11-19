#pragma once
#include "ConfiguracionMenuBackups.h"
#include "ConfiguracionMenuExportarCSV.h"

class ConfiguracionMenu{
public:
    ConfiguracionMenu();

    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpciones();
    void ejecutarOpciones(int opcion);

    ConfiguracionMenuBackups _configuracionMenuBackups;
    ConfiguracionMenuExportarCSV _configuracionMenuExportarCSV;
private:
    int _cantidadOpciones;
};

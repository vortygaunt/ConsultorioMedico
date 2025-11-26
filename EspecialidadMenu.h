#pragma once
#include "Menu.h"
#include "EspecialidadManager.h"

class EspecialidadMenu: public Menu{
public:
    EspecialidadMenu();

protected:
    void mostrarOpciones();
    void ejecutarOpciones(int opcion);

    EspecialidadManager _especialidadManager;
private:

};

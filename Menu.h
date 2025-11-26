#pragma once

class Menu{
  public:
  Menu();

    void mostrar();

protected:
    virtual void mostrarOpciones();
    int seleccionarOpciones();
    virtual void ejecutarOpciones(int opcion);
    int _cantidadOpciones;
private:

};

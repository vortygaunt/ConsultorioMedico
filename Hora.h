#pragma once

class Hora{
public:
    Hora();

    void setHora(int hora);
    void setMinuto(int minuto);

    int getHora();
    int getMinuto();

    void cargar();
    void mostrar();
private:
    int _hora;
    int _minuto;
};

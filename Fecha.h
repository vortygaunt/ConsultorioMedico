#pragma once

class Fecha{
public:
    Fecha();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();

    void cargar();
    void mostrar();
private:
    int _dia;
    int _mes;
    int _anio;
};

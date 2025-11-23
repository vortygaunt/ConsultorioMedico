#pragma once
#include <string>
#include "HistoriaClinica.h"

using namespace std;

class HistoriaClinicaArchivo {
private:
    string _nombreArchivo;

public:

    HistoriaClinicaArchivo(std::string nombreArchivo = "historiasClinicas.dat");
    bool guardar(HistoriaClinica registro);
    HistoriaClinica leer(int pos);
    bool modificar(int pos, HistoriaClinica &registro);
    bool eliminar(int pos);
    int getCantidadRegistro();
    int getNuevoID();

};

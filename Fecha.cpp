#include <iostream>
#include "Fecha.h"
#include "funcionesGlobales.h"

using namespace std;

    Fecha::Fecha()
    : _dia(0), _mes(0), _anio(0){

    }

    void Fecha::setDia(int dia){
       if(dia > 0){
        _dia = dia;
       }
    }

    void Fecha::setMes(int mes){
        if(mes > 0 && mes <= 12){
            _mes = mes;
        }
    }
    void Fecha::setAnio(int anio){
        if(anio > 0){
            _anio = anio;
        }
    }

    int Fecha::getDia(){
        return _dia;
    }
    int Fecha::getMes(){
        return _mes;
    }
    int Fecha::getAnio(){
        return _anio;
    }

    void Fecha::cargar() {
    int dia, mes, anio;

    // CARGAR AÑO
    do {
        anio = leerEntero("Ingrese el año: ");
        if (anio <= 0) {
            cout << "Año inválido. Debe ser mayor a 0." << endl;
        }
    } while (anio <= 0);

    // CARGAR MES
    do {
        mes = leerEntero("Ingrese el mes: ");
        if (mes < 1 || mes > 12) {
            cout << "Mes inválido. Debe estar entre 1 y 12." << endl;
        }
    } while (mes < 1 || mes > 12);

    // CALCULAR DÍAS MÁXIMOS
    int maxDia = 31;

    switch (mes) {
        case 4: case 6: case 9: case 11:
            maxDia = 30;
            break;

        case 2:
            maxDia = esBiciesto(anio) ? 29 : 28;
            break;
    }

    // CARGAR DÍA
    do {
        dia = leerEntero("Ingrese el día: ");
        if (dia < 1 || dia > maxDia) {
            cout << "Día inválido para el mes ingresado. ";
            cout << "Debe estar entre 1 y " << maxDia << "." << endl;
        }
    } while (dia < 1 || dia > maxDia);

    // Asignar valores
   setAnio(anio);
   setMes(mes);
   setDia(dia);
}

    void Fecha::mostrar(){
        cout << _dia << "/" << _mes << "/" << _anio << endl;
    }

    bool Fecha::esBiciesto(int anio){
        return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    }

    bool Fecha::operator==(const Fecha &otra) const {
        return _dia == otra._dia && _mes == otra._mes && _anio == otra._anio;
    }

    bool Fecha::operator>(const Fecha& otra) const {
       if(_anio != otra._anio){
        return _anio > otra._anio;
       }

       if(_mes != otra._mes){
        return _mes > otra._mes;
       }

        return _dia > otra._dia;

    }

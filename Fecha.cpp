#include <iostream>
#include "Fecha.h"

using namespace std;

    Fecha::Fecha()
    : _dia(0), _mes(0), _anio(0){

    }

    void Fecha::setDia(int dia){
        int maxDia = 31;

        if(_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11){
            maxDia = 30;
        }

        if(_mes == 2){
            if(esBiciesto(_anio)){
                maxDia = 29;
            }else{
                maxDia = 28;
            }
        }

        if(dia > 0 && dia <= maxDia){
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

    void Fecha::cargar(){
        int dia, mes, anio;
        cout << "Ingrese el dia: ";
        cin >> dia;
        cout << "Ingrese el mes: ";
        cin >> mes;
        cout << "Ingrese el anio: ";
        cin >> anio;

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

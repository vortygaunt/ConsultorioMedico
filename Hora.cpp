#include <iostream>
#include "Hora.h"

using namespace std;

    Hora::Hora()
    :_hora(0), _minuto(0){

    }

    void Hora::setHora(int hora){
        if(hora >= 0 && hora <= 23){
            _hora = hora;
        }
    }
    void Hora::setMinuto(int minuto){
        if(minuto >= 0 && minuto <= 59){
            _minuto = minuto;
        }
    }

    int Hora::getHora(){
        return _hora;
    }
    int Hora::getMinuto(){
        return _minuto;
    }

    void Hora::cargar(){
        int hora, minuto;

        cout << "Ingrese la hora: ";
        cin >> hora;
        cout << "Ingrese el minuto: ";
        cin >> minuto;

        setHora(hora);
        setMinuto(minuto);
    }

    void Hora::mostrar(){
        if(_hora < 10){
            cout << "0";
        }
        cout << _hora << ":";

        if(_minuto < 10){
            cout << "0";
        }
        cout << _minuto << endl;
    }

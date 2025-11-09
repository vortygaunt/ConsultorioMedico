#include <iostream>
#include "Hora.h"

using namespace std;

    Hora::Hora()
    :_hora(0), _minuto(0){

    }

    void Hora::setHora(int hora){
        _hora = hora;
    }
    void Hora::setMinuto(int minuto){
        _minuto = minuto;
    }

    int Hora::getHora(){
        return _hora;
    }
    int Hora::getMinuto(){
        return _minuto;
    }

    void Hora::cargar(){
        cout << "Ingrese la hora: ";
        cin >> _hora;
        cout << "Ingrese el minuto: ";
        cin >> _minuto;
    }
    void Hora::mostrar(){
        cout << _hora << ":" << _minuto << endl;
    }

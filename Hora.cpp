#include <iostream>
#include "Hora.h"
#include "funcionesGlobales.h"

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

    do{
        hora = leerEntero("Ingrese la hora (0-23): ");
        if(hora < 0 || hora > 23){
            cout << "Hora inválida. Debe estar entre 0 y 23." << endl;
        }
    } while(hora < 0 || hora > 23);

    do{
        minuto = leerEntero("Ingrese los minutos (0-59): ");
        if(minuto < 0 || minuto > 59){
            cout << "Minuto inválido. Debe estar entre 0 y 59." << endl;
        }
    } while(minuto < 0 || minuto > 59);

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

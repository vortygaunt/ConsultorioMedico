#include <iostream>
#include <cstring>
#include "PacienteDireccion.h"
#include "funcionesGlobales.h"

using namespace std;

PacienteDireccion::PacienteDireccion()
{
   strcpy(_calle, "");
    _numero = 0;
    strcpy(_localidad, "");
}

void PacienteDireccion::setCalle(const string &calle) {
    strncpy(_calle, calle.c_str(), sizeof(_calle) - 1);
    _calle[sizeof(_calle) - 1] = '\0';
}

void PacienteDireccion::setNumero(int numero) {
    if(numero > 0){
        _numero = numero;
    }
}

void PacienteDireccion::setLocalidad(const string &localidad) {
    strncpy(_localidad, localidad.c_str(), sizeof(_localidad) - 1);
    _localidad[sizeof(_localidad) - 1] = '\0';
}

string PacienteDireccion::getCalle(){
    return string(_calle);
}

int PacienteDireccion::getNumero(){
    return _numero;
}

string PacienteDireccion::getLocalidad(){
    return string(_localidad);
}

void PacienteDireccion::cargar() {
    string calle;
    string localidad;
    int numero;
    bool valido;

    do{
        cout << "CALLE: ";
        calle = cargarCadena();

        valido = soloDigitosyLetras(calle);

            if(!valido){
                cout << "Calle invalida." << endl;
            }

    }while(!valido);
    setCalle(calle);

    do{
        numero = leerEntero("NUMERO: ");

        if(numero <= 0){
            cout << "Numero de calle invalido." << endl;
        }

    }while(numero <= 0);
    setNumero(numero);

    do{
        cout << "LOCALIDAD: ";
        localidad = cargarCadena();

        valido = soloLetras(localidad);

        if(!valido){
            cout << "Localidad invalida." << endl;
        }

    }while(!valido);
    setLocalidad(localidad);
}


void PacienteDireccion::mostrar(){

    cout<<"CALLE: "<< _calle <<endl;
    cout<<"NUMERO: "<< _numero <<endl;
    cout<<"LOCALIDAD: "<< _localidad <<endl;
}


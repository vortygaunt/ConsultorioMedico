#include <iostream>
#include <cstring>
#include "PacienteDireccion.h"

using namespace std;

PacienteDireccion::PacienteDireccion()
{
   strcpy(_calle, "");
    _numero = 0;
    strcpy(_localidad, "");
}

void PacienteDireccion::setCalle(const char* calle) {
    strncpy(_calle, calle, sizeof(_calle) - 1);
}

void PacienteDireccion::setNumero(int numero) {
    _numero = numero;
}

void PacienteDireccion::setLocalidad(const char* localidad) {
    strncpy(_localidad, localidad, sizeof(_localidad) - 1);
}

const char* PacienteDireccion::getCalle() const {
    return _calle;
}

int PacienteDireccion::getNumero() const {
    return _numero;
}

const char* PacienteDireccion::getLocalidad() const {
    return _localidad;
}

void PacienteDireccion::cargar() {
    char aux[50];

    cout << "CALLE: ";
    cin.ignore();
    cin.getline(aux, 50);
    setCalle(aux);

    cout << "NUMERO: ";
    cin >> _numero;
    cin.ignore();

    cout << "LOCALIDAD: ";
    cin.getline(aux, 50);
    setLocalidad(aux);
}


void PacienteDireccion::mostrar()const{

    cout<<"CALLE "<< _calle <<endl;
    cout<<"NUMERO "<< _numero <<endl;
    cout<<"LOCALIDAD "<< _localidad <<endl;
}

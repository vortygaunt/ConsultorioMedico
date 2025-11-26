#include <iostream>
#include <cstring>
#include "Especialidad.h"

using namespace std;

Especialidad::Especialidad()
: _codigoEspecialidad(0), _estado(false){
    strcpy(_descripcion, "");
}

Especialidad::Especialidad(int codigoEspecialidad, string descripcion, bool estado){
    setCodigoEspecialidad(codigoEspecialidad);
    setDescripcion(descripcion);
    setEstado(estado);
}

void Especialidad::setCodigoEspecialidad(int codigoEspecialidad){
    if(codigoEspecialidad > 0){
        _codigoEspecialidad = codigoEspecialidad;
    }
}

void Especialidad::setDescripcion(string descripcion){
    strncpy(_descripcion, descripcion.c_str(), 49);
    _descripcion[49] = '\0';
}

void Especialidad::setEstado(bool estado){
    _estado = estado;
}

int Especialidad::getCodigoEspecialidad(){
    return _codigoEspecialidad;
}

string Especialidad::getDescripcion(){
    return string (_descripcion);
}

bool Especialidad::getEstado(){
    return _estado;
}

void Especialidad::mostrar(){
    cout << "Codigo de especialidad: " << _codigoEspecialidad << endl;
    cout << "Descripcion: " << _descripcion << endl;
}

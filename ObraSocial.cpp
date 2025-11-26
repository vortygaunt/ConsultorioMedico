#include <iostream>
#include <cstring>
#include "ObraSocial.h"

using namespace std;

    ObraSocial::ObraSocial()
    :_idObraSocial(0), _estado(true){
        strcpy(_nombre, "");
        strcpy(_telefonoObraSocial, "");
    }

    ObraSocial::ObraSocial(int idObraSocial, string nombre, string telefonoObraSocial, bool estado){
        setIdObraSocial(idObraSocial);
        setNombre(nombre);
        setTelefonoObraSocial(telefonoObraSocial);
        setEstado(estado);
    }

    void ObraSocial::setIdObraSocial(int idObraSocial){
        if(idObraSocial > 0){
            _idObraSocial = idObraSocial;
        }
    }
    void ObraSocial::setNombre(string nombre){
        strncpy(_nombre, nombre.c_str(), 29);
        _nombre[29] = '\0';
    }
    void ObraSocial::setTelefonoObraSocial(string telefonoObraSocial){
        strncpy(_telefonoObraSocial, telefonoObraSocial.c_str(), 19);
        _telefonoObraSocial[19] = '\0';
    }
    void ObraSocial::setEstado(bool estado){
        _estado = estado;
    }

    int ObraSocial::getIdObraSocial(){
        return _idObraSocial;
    }
    string ObraSocial::getNombre(){
        return _nombre;
    }
    string ObraSocial::getTelefonoObraSocial(){
        return _telefonoObraSocial;
    }
    bool ObraSocial::getEstado(){
        return _estado;
    }

    void ObraSocial::mostrar(){
        cout << "ID de la obra social: " << _idObraSocial << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Telefono: " << _telefonoObraSocial << endl;
    }

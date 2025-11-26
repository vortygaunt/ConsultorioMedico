#include <iostream>
#include "TurnoArchivo.h"

using namespace std;

TurnoArchivo::TurnoArchivo(string nombreArchivo)
:_nombreArchivo(nombreArchivo){

}

bool TurnoArchivo::guardar(Turno registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }

    resultado = fwrite(&registro, sizeof(Turno), 1, pFile);

    fclose(pFile);

    return resultado;
}

Turno TurnoArchivo::leer(int pos){
    FILE *pFile;
    Turno registro;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, sizeof(Turno)*pos, SEEK_SET);

    fread(&registro, sizeof(Turno), 1, pFile);

    fclose(pFile);

    return registro;
}

bool TurnoArchivo::modificar(int pos, Turno &registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, sizeof(Turno)*pos, SEEK_SET);

    resultado = fwrite(&registro, sizeof(Turno), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool TurnoArchivo::eliminar(int pos){
    Turno registro;

    registro = leer(pos);
    registro.setEstado(0);

    return modificar(pos, registro);
}

int TurnoArchivo::getCantidadRegistro(){
    FILE *pFile;
    Turno registro;
    int cantidad;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    cantidad = ftell(pFile) / sizeof(Turno);

    fclose(pFile);

    return cantidad;
}

int  TurnoArchivo::getNuevoID(){
    return getCantidadRegistro() + 1;
}

void TurnoArchivo::vaciarArchivo(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");

    fclose(pFile);
}

bool TurnoArchivo::existe(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
      return false;
    }

    fclose(pFile);

    return true;
}

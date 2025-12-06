#include <iostream>
#include "EspecialidadArchivo.h"

using namespace std;

EspecialidadArchivo::EspecialidadArchivo(string nombreArchivo)
:_nombreArchivo(nombreArchivo){

}

bool EspecialidadArchivo::guardar(Especialidad registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }

    resultado = fwrite(&registro, sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return resultado;
}

Especialidad EspecialidadArchivo::leer(int pos){
    FILE *pFile;
    Especialidad registro;

    if(pos < 0 || pos >= getCantidadRegistro()){
            return registro;
    }

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, sizeof(Especialidad)*pos, SEEK_SET);

    fread(&registro, sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return registro;
}

bool EspecialidadArchivo::modificar(int pos, Especialidad &registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr){
        return false;
    }

    if(pos < 0 || pos >= getCantidadRegistro()){
        return false;
    }

    fseek(pFile, sizeof(Especialidad)*pos, SEEK_SET);

    resultado = fwrite(&registro, sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return resultado;
}

bool EspecialidadArchivo::eliminar(int pos){
    Especialidad registro;

    if(pos < 0 || pos >= getCantidadRegistro()){
        return false;
    }

    registro = leer(pos);
    registro.setEstado(false);

    return modificar(pos, registro);
}

int EspecialidadArchivo::getCantidadRegistro(){
    FILE *pFile;
    Especialidad registro;
    int cantidad;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    cantidad = ftell(pFile) / sizeof(Especialidad);

    fclose(pFile);

    return cantidad;
}

 int EspecialidadArchivo::getNuevoCodigo(){
    return getCantidadRegistro() + 1;
 }

void EspecialidadArchivo::vaciarArchivo(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");

    fclose(pFile);
}

bool EspecialidadArchivo::existe(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    fclose(pFile);

    return true;
}

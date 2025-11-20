#include <iostream>
#include "ObraSocialArchivo.h"

using namespace std;

    ObraSocialArchivo::ObraSocialArchivo(string nombreArchivo)
    :_nombreArchivo(nombreArchivo) {

    }

    bool ObraSocialArchivo::guardar(ObraSocial registro){
        FILE *pFile;
        bool resultado;

        pFile = fopen(_nombreArchivo.c_str(), "ab");
        if(pFile == nullptr){
            return false;
        }

        resultado = fwrite(&registro, sizeof(ObraSocial), 1, pFile);

        fclose(pFile);

        return resultado;
    }

    ObraSocial ObraSocialArchivo::leer(int pos){
        FILE *pFile;
        ObraSocial registro;

        pFile = fopen(_nombreArchivo.c_str(), "rb");
        if(pFile == nullptr){
            return registro;
        }

        fseek(pFile, sizeof(ObraSocial)*pos, SEEK_SET);

        fread(&registro, sizeof(ObraSocial), 1, pFile);

        fclose(pFile);

        return registro;
    }

    bool ObraSocialArchivo::modificar(int pos, ObraSocial &registro){
        FILE *pFile;
        bool resultado;

        pFile = fopen(_nombreArchivo.c_str(), "rb+");
        if(pFile == nullptr){
            return false;
        }

        fseek(pFile, sizeof(ObraSocial)*pos, SEEK_SET);

        resultado = fwrite(&registro, sizeof(ObraSocial), 1, pFile);

        fclose(pFile);

        return resultado;
    }

    bool ObraSocialArchivo::eliminar(int pos){
        ObraSocial registro;

        registro = leer(pos);
        registro.setEstado(false);

        return modificar(pos, registro);
    }

    int ObraSocialArchivo::getCantidadRegistro(){
        FILE *pFile;
        ObraSocial registro;
        int cantidad;

        pFile = fopen(_nombreArchivo.c_str(), "rb");
        if(pFile == nullptr){
            return 0;
        }

        fseek(pFile, 0, SEEK_END);

        cantidad = ftell(pFile) / sizeof(ObraSocial);

        fclose(pFile);

        return cantidad;
    }

    int ObraSocialArchivo::getnuevoID(){
        return getCantidadRegistro() + 1;
    }

    void ObraSocialArchivo::vaciarArchivo(){
        FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
        fclose(pFile);
    }

    bool ObraSocialArchivo::existe(){
        FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
        if (pFile == nullptr) {
            return false;
        }
        fclose(pFile);
        return true;
    }

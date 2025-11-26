#include <iostream>
#include "ConsultorioArchivo.h"

using namespace std;

    ConsultorioArchivo::ConsultorioArchivo(string nombreArchivo)
    :_nombreArchivo(nombreArchivo){

    }

    bool ConsultorioArchivo::guardar(Consultorio registro){
        FILE *pFile;
        bool resultado;

        pFile = fopen(_nombreArchivo.c_str(), "ab");
        if(pFile == nullptr){
            return false;
        }

        resultado = fwrite(&registro, sizeof(Consultorio), 1, pFile);

        fclose(pFile);

        return resultado;
    }

    Consultorio ConsultorioArchivo::leer(int pos){
        FILE *pFile;
        Consultorio registro;

        pFile = fopen(_nombreArchivo.c_str(), "rb");
        if(pFile == nullptr){
            return registro;
        }

        fseek(pFile, sizeof(Consultorio)*pos, SEEK_SET);

        fread(&registro, sizeof(Consultorio), 1, pFile);

        fclose(pFile);

        return registro;
    }

    bool ConsultorioArchivo::modificar(int pos, Consultorio &registro){
        FILE *pFile;
        bool resultado;

        pFile = fopen(_nombreArchivo.c_str(), "rb+");
        if(pFile == nullptr){
            return false;
        }

        fseek(pFile, sizeof(Consultorio)*pos, SEEK_SET);

        resultado = fwrite(&registro, sizeof(Consultorio), 1, pFile);

        fclose(pFile);

        return resultado;
    }

    bool ConsultorioArchivo::eliminar(int pos){
        Consultorio registro;

        registro = leer(pos);
        registro.setEstado(false);

        return modificar(pos, registro);
    }

    int ConsultorioArchivo::getCantidadRegistro(){
        FILE *pFile;
        Consultorio registro;
        int cantidad;

        pFile = fopen(_nombreArchivo.c_str(), "rb");
        if(pFile == nullptr){
            return 0;
        }

        fseek(pFile, 0, SEEK_END);

        cantidad = ftell(pFile) / sizeof(Consultorio);

        fclose(pFile);

        return cantidad;
    }

    void ConsultorioArchivo::vaciarArchivo(){
        FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
        fclose(pFile);
    }

      bool ConsultorioArchivo::existe(){
        FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
        if (pFile == nullptr) {
            return false;
        }
        fclose(pFile);
        return true;
    }


#include <iostream>
#include "MedicoArchivo.h"

using namespace std;

    MedicoArchivo::MedicoArchivo(string nombreArchivo)
    :_nombreArchivo(nombreArchivo) {

    }

    bool MedicoArchivo::guardar(Medico registro){
        FILE *pFile;
        bool resultado;

        pFile = fopen(_nombreArchivo.c_str(), "ab");
        if(pFile == nullptr){
            return false;
        }

        resultado = fwrite(&registro, sizeof(Medico), 1, pFile);

        fclose(pFile);

        return resultado;
    }

    Medico MedicoArchivo::leer(int pos){
        FILE *pFile;
        Medico registro;

        pFile = fopen(_nombreArchivo.c_str(), "rb");
        if(pFile == nullptr){
            return registro;
        }

        fseek(pFile, sizeof(Medico)*pos, SEEK_SET);

        fread(&registro, sizeof(Medico), 1, pFile);

        fclose(pFile);

        return registro;
    }

    bool MedicoArchivo::modificar(int pos, Medico &registro){
        FILE *pFile;
        bool resultado;

        pFile = fopen(_nombreArchivo.c_str(), "rb+");
        if(pFile == nullptr){
            return false;
        }

        fseek(pFile, sizeof(Medico)*pos, SEEK_SET);

        resultado = fwrite(&registro, sizeof(Medico), 1, pFile);

        fclose(pFile);

        return resultado;
    }

    bool MedicoArchivo::eliminar(int pos){
        Medico registro;

        registro = leer(pos);
        registro.setEstado(false);

        return modificar(pos, registro);
    }

    int MedicoArchivo::getCantidadRegistro(){
        FILE *pFile;
        Medico registro;
        int cantidad;

        pFile = fopen(_nombreArchivo.c_str(), "rb");
        if(pFile == nullptr){
            return 0;
        }

        fseek(pFile, 0, SEEK_END);

        cantidad = ftell(pFile) / sizeof(Medico);

        fclose(pFile);

        return cantidad;
    }

    int MedicoArchivo::getnuevoID(){
        return getCantidadRegistro() + 1;
    }

    bool MedicoArchivo::existeID(int id){
        Medico registro;
        int cantidad;

        cantidad = getCantidadRegistro();
        if(cantidad == 0){
            return false;
        }

        for(int i= 0; i < cantidad; i++){
            registro = leer(i);
            if(registro.getIdMedico() == id && registro.getEstado()){
                return true;
            }
        }

        return false;
    }

    bool MedicoArchivo::existeDNI(string dni){
        int cantidad;
        Medico registro;

        cantidad = getCantidadRegistro();
        if(cantidad == 0){
            return false;
        }

        for(int i=0; i<cantidad; i++){
            registro = leer(i);
            if(registro.getEstado() && dni == registro.getDniMedico()){
                return true;
            }
        }
        return false;
    }

    void MedicoArchivo::vaciarArchivo() {
        FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
        fclose(pFile);
    }

    bool MedicoArchivo::existe(){
        FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
        if (pFile == nullptr) {
            return false;
        }
        fclose(pFile);
        return true;
    }

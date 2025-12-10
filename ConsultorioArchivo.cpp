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

        if(pos < 0 || pos >= getCantidadRegistro()){
            return registro;
        }

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

        if(pos < 0 || pos >= getCantidadRegistro()){
            return false;
        }

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

         if(pos < 0 || pos >= getCantidadRegistro()){
            return false;
        }

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

    bool ConsultorioArchivo::existeConsultorio(int numero){
        Consultorio registro;
        int cantidad;

        cantidad = getCantidadRegistro();
        if(cantidad == 0){
            return false;
        }

        for(int i= 0; i < cantidad; i++){
            registro = leer(i);
            if(registro.getNumeroConsultorio() == numero && registro.getEstado() == true){
                return true;
            }
        }

        return false;
    }

        bool ConsultorioArchivo::usarConsultorio(int numeroConsultorio, int idMedico){

        int cantidad = getCantidadRegistro();
        if(cantidad == 0){
            return false;
        }

        Consultorio reg;
        int pos = -1;

        for (int i = 0; i < cantidad; i++){
            reg = leer(i);
            if (reg.getNumeroConsultorio() == numeroConsultorio){
                pos = i;
                break;
            }
        }

        if (pos == -1){
            return false;
        }

        if(reg.getOcupado() == true){
            if(reg.getIdMedico() != idMedico){
                return false;
            }
            else{
                return true;
            }

        }

        reg.setOcupado(true);
        reg.setIdMedico(idMedico);


        return modificar(pos, reg);

    }

    bool ConsultorioArchivo::liberarConsultorio(int numeroConsultorio){

        int cantidad = getCantidadRegistro();
        if(cantidad == 0){
            return false;
        }

        Consultorio reg;
        int pos = -1;

        for (int i = 0; i < cantidad; i++) {
            reg = leer(i);
            if (reg.getNumeroConsultorio() == numeroConsultorio) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            return false;
        }

        if (reg.getOcupado() == false) {
            return true;
        }

        reg.setOcupado(false);
        reg.setIdMedico(0);  // 0 = nadie

        return modificar(pos, reg);

    }


    void ConsultorioArchivo::vaciarArchivo(){
        FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
        if(pFile == nullptr){
            return;
        }
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


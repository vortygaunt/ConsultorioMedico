#include <iostream>
#include "HistoriaClinicaArchivo.h"

using namespace std;
HistoriaClinicaArchivo::HistoriaClinicaArchivo(std::string nombreArchivo):_nombreArchivo(nombreArchivo){

}

bool HistoriaClinicaArchivo::guardar(HistoriaClinica registro) {
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if (pFile == nullptr){
        std::cout << "No se pudo guardar el registro";
        return false;
    }

    resultado = fwrite(&registro, sizeof(HistoriaClinica), 1, pFile);
    fclose(pFile);

    return resultado;
}

HistoriaClinica HistoriaClinicaArchivo::leer(int pos) {
    HistoriaClinica reg;
    FILE *pFile;

    if(pos < 0 || pos >= getCantidadRegistro()){
        return reg;
    }

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr){
        std::cout << "No se pudo leer el registro";
        return reg;
    }

    fseek(pFile, pos * sizeof(HistoriaClinica), SEEK_SET);
    fread(&reg, sizeof(HistoriaClinica), 1, pFile);

    fclose(pFile);
    return reg;
}


bool HistoriaClinicaArchivo::modificar(int pos, HistoriaClinica &registro) {
    FILE *pFile;
    bool resultado;

    if(pos < 0 || pos >= getCantidadRegistro()){
        return false;
    }

    pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == nullptr) {
        std::cout << "No se pudo modificar el registro";
        return false;
    }

    fseek(pFile, pos * sizeof(HistoriaClinica), SEEK_SET);
    resultado = fwrite(&registro, sizeof(HistoriaClinica), 1, pFile);

    fclose(pFile);
    return resultado;
}

int HistoriaClinicaArchivo::getCantidadRegistro() {
    FILE *pFile;
    int cantidad;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof (HistoriaClinica);

    fclose(pFile);

    return cantidad;
}

int HistoriaClinicaArchivo::getNuevoID(){
    return getCantidadRegistro() + 1;
    }

int HistoriaClinicaArchivo::buscarPosPorDni(const std::string &dniBuscado) {
    int cantidad = getCantidadRegistro();
    if(cantidad == 0){
        return -1;
    }

    for (int i = 0; i < cantidad; i++) {
        HistoriaClinica reg = leer(i);

        if (reg.getEstado() && reg.getDniPaciente() == dniBuscado) {
            return i;
        }
    }

    return -1;  // no encontrado
}

void HistoriaClinicaArchivo::vaciarArchivo() {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
    fclose(pFile);
}

bool HistoriaClinicaArchivo::existe(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return false;
    }
    fclose(pFile);
    return true;
}

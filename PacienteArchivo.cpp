#include <iostream>
#include "PacienteArchivo.h"

PacienteArchivo::PacienteArchivo(std::string nombreArchivo):_nombreArchivo(nombreArchivo) {

}


bool PacienteArchivo::guardar(Paciente registro) {

    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if (pFile == nullptr){
        std::cout << "No se pudo guardar el registro";
        return false;
    }

    resultado = fwrite(&registro, sizeof(Paciente), 1, pFile);
    fclose(pFile);

    return resultado;

}

Paciente PacienteArchivo::leer(int pos) {
    FILE *pFile;
    Paciente reg;


    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr){
        std::cout << "No se pudo leer el registro";
        return reg;
    }

    fseek(pFile, pos * sizeof(Paciente), SEEK_SET);
    fread(&reg, sizeof(Paciente), 1, pFile);

    fclose(pFile);
    return reg;
}

bool PacienteArchivo::modificar(int pos, Paciente& registro) {
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == nullptr) {
        std::cout << "No se pudo modificar el registro";
        return false;
    }

    fseek(pFile, pos * sizeof(Paciente), SEEK_SET);
    resultado = fwrite(&registro, sizeof(Paciente), 1, pFile);

    fclose(pFile);
    return resultado;
}

int PacienteArchivo::getCantidadRegistro() {
    FILE *pFile;
    int cantidad;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    cantidad = ftell(pFile) / sizeof (Paciente);

    fclose(pFile);

    return cantidad;
}

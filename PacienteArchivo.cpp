#include <iostream>
#include "PacienteArchivo.h"

using namespace std;

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

    if(pos < 0 || pos >= getCantidadRegistro()){
        return reg;
    }

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

    if(pos < 0 || pos >= getCantidadRegistro()){
        return false;
    }

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

bool PacienteArchivo::eliminar(int pos){
    Paciente registro;

    if(pos < 0 || pos >= getCantidadRegistro()){
        return false;
    }

    registro = leer(pos);
    registro.setEstadoPaciente(false);

    return modificar(pos, registro);
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

bool PacienteArchivo::existeDNI(string dni){
    int cantidad;
    Paciente registro;

    cantidad = getCantidadRegistro();
    if(cantidad == 0){
        return false;
    }

    for(int i=0; i<cantidad; i++){
        registro = leer(i);
        if(dni == registro.getDniPaciente() && registro.getEstadoPaciente()){
            return true;
        }
    }
    return false;
}

int PacienteArchivo::buscarPosPorDni(string& dniBuscado)
{
    int cantidad = getCantidadRegistro();
    if(cantidad == 0){
        return -1;
    }

    for (int i = 0; i < cantidad; i++) {
        Paciente reg = leer(i);

        if (reg.getEstadoPaciente() && reg.getDniPaciente() == dniBuscado) {
            return i;
        }
    }

    return -1; // no encontrado
}

void PacienteArchivo::vaciarArchivo() {
        FILE *pFile = fopen(_nombreArchivo.c_str(), "wb");
        fclose(pFile);
    }

bool PacienteArchivo::existe(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return false;
    }
    fclose(pFile);
    return true;
}


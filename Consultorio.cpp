#include <iostream>
#include "Consultorio.h"

using namespace std;

    Consultorio::Consultorio()
    :_numeroConsultorio(0), _pisoConsultorio(0), _codigoEspecialidad(0), _ocupado(false), _idMedico(0), _estado(false){

    }

    Consultorio::Consultorio(int numeroConsultorio, int pisoConsultorio, int codigoEspecialidad, bool ocupado, int idMedico, bool estado){
        setNumeroConsultorio(numeroConsultorio);
        setPisoConsultorio(pisoConsultorio);
        setCodigoEspecialidad(codigoEspecialidad);
        setOcupado(ocupado);
        setIdMedico(idMedico);
        setEstado(estado);
    }

    void Consultorio::setNumeroConsultorio(int numeroConsultorio){
        if(numeroConsultorio > 0){
            _numeroConsultorio = numeroConsultorio;
        }
    }
    void Consultorio::setPisoConsultorio(int pisoConsultorio){
        if(pisoConsultorio > 0){
            _pisoConsultorio = pisoConsultorio;
        }
    }
    void Consultorio::setCodigoEspecialidad(int codigoEspecialidad){
         if(codigoEspecialidad > 0){
            _codigoEspecialidad = codigoEspecialidad;
        }
    }
    void Consultorio::setOcupado(bool ocupado){
        _ocupado = ocupado;
    }
    void Consultorio::setIdMedico(int idMedico){
            if(_idMedico >= 0){
             _idMedico = idMedico;
            }
    }
    void Consultorio::setEstado(bool estado){
        _estado = estado;
    }

    int Consultorio::getNumeroConsultorio(){
        return _numeroConsultorio;
    }
    int Consultorio::getPisoConsultorio(){
        return _pisoConsultorio;
    }
    int Consultorio::getCodigoEspecialidad(){
        return _codigoEspecialidad;
    }
    bool Consultorio::getOcupado(){
        return _ocupado;
    }
    int Consultorio::getIdMedico(){
        return _idMedico;
    }
    bool Consultorio::getEstado(){
        return _estado;
    }

    void Consultorio::mostrar(){
        cout << "Numero del consultorio: " << _numeroConsultorio << endl;
        cout << "Piso del consultorio: " << _pisoConsultorio << endl;
        cout << "Codigo de especialidad asignado: " << _codigoEspecialidad << endl;
        cout << "Estado: " << (_ocupado ? "Ocupado" : "Libre") << endl;

        if(_ocupado){
            cout << "ID del medico que ocupa el consultorio: " << _idMedico << endl;
        }else{
            cout << "ID del medico que ocupa el consultorio: --- " << endl;
        }
        cout << "------------------------------------------------" << endl;
    }

#include <iostream>
#include "ReporteManager.h"
#include "Fecha.h"
#include "funcionesGlobales.h"

using namespace std;

void ReporteManager::facturacionMensualYAnual(){
    int cantidad = _repoTurno.getCantidadRegistro();

    if (cantidad == 0)
    {
        cout<< "No hay turnos cargados"<<endl;
        return;
    }

    float sumaMensual[12]={0};
    const int maxAnios = 50;
    int listaAnios[maxAnios];
    float sumaAnual[maxAnios];
    int usados = 0;

    for (int i = 0; i < maxAnios; i++) { //inicializamos
        listaAnios[i] = 0;
        sumaAnual[i] = 0;
    }

    //recorre los turnos
    for (int i = 0; i < cantidad; i++) {
        Turno _turno = _repoTurno.leer(i);

        if (_turno.getEstado()) {

            Fecha _fecha = _turno.getFechaAtencion();
            int mes = _fecha.getMes();
            int anio = _fecha.getAnio();
            float importe = _turno.getImporteConsulta();


            if (mes >= 1 && mes <= 12) { //acumula por mes
            sumaMensual[mes - 1] += importe;
            }


            int pos = -1;
            for (int j = 0; j < usados; j++) { //acumula por anio
                if (listaAnios[j] == anio) {
                    pos = j;
                    break;
                }
            }


            if (pos == -1) {
                pos = usados;
                listaAnios[usados] = anio;
                usados++;
            }

            sumaAnual[pos] += importe;
        }

    }

    cout << "======================================" << endl;
    cout << "        FACTURACION MENSUAL"            << endl;
    cout << "======================================" << endl;

    const char *nombreMes[12] =
        {"Enero","Febrero","Marzo","Abril","Mayo","Junio",
        "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    for (int i = 0; i < 12; i++) {

        cout << nombreMes[i] << ": $ " << sumaMensual[i] << endl;
    }

    cout << endl;
    cout << "======================================" << endl;
    cout << "         FACTURACION ANUAL" << endl;
    cout << "======================================" << endl;

    for (int i = 0; i < usados; i++) {
    cout << listaAnios[i] << ": $ " << sumaAnual[i] << endl;
    }

}


void ReporteManager::facturacionPorMedico(){

    Fecha fechaInicio, fechaFin;
    int idMedico;

    idMedico = leerEntero("Ingrese el ID del medico: ");
    if(idMedico <= 0){
        cout << "ID invalido." << endl;
        return;
    }

    if(!_repoMedico.existeID(idMedico)){
        cout << "El ID ingresado no existe." << endl;
        return;
    }

    cout << "FECHA DESDE: " << endl;
    fechaInicio.cargar();

    cout << "FECHA HASTA: " << endl;
    fechaFin.cargar();

    int cantidad = _repoTurno.getCantidadRegistro();

    if (cantidad == 0) {
        cout << "No hay turnos cargados." << endl;
        return;
    }


    float totalFacturado = 0;
    bool hayTurnos = false;

    cout<< endl;
    cout<< "Turnos facturados para el medico: " << idMedico
     << " entre "
     << fechaInicio.getDia() << "/" << fechaInicio.getMes() << "/" << fechaInicio.getAnio()
     << " y "
     << fechaFin.getDia() << "/" << fechaFin.getMes() << "/" << fechaFin.getAnio()
     << ":" << endl;
    cout<< "======================================================================="<<endl;



    for (int i = 0; i < cantidad; i++) {

        Turno _turno = _repoTurno.leer(i);

        if (_turno.getEstado()) {

            if (_turno.getIdMedico() == idMedico) {

                Fecha _fecha = _turno.getFechaAtencion();

                bool _fechaInicio = (_fecha == fechaInicio) || (_fecha > fechaInicio);

                bool _fechaFin =!(_fecha > fechaFin);

                if(_fechaInicio && _fechaFin){
                    hayTurnos = true;

                    cout << _fecha.getDia() << "/" << _fecha.getMes() << "/" << _fecha.getAnio();
                    cout << "  -  $" << _turno.getImporteConsulta() << endl;

                    totalFacturado += _turno.getImporteConsulta();
                }
            }

        }

    }

    cout << "---------------------------------------------------------" << endl;

    if(hayTurnos){
        cout << "TOTAL FACTURADO: $" << totalFacturado << endl;
    }
    else{
        cout << "No hay turnos en el rango indicado." << endl;
    }

}



void ReporteManager::turnosPorEspecialidad(){


    int cantTurnos = _repoTurno.getCantidadRegistro();
    int cantEsp = _repoEspecialidad.getCantidadRegistro();

    if (cantTurnos == 0) {
        cout << "No hay turnos cargados." << endl;
        return;
    }
    if (cantEsp == 0) {
        cout << "No hay especialidades cargadas." << endl;
        return;
    }


    const int maxEspecialidad = 100;
    int idEsp[maxEspecialidad];
    int contador[maxEspecialidad] = {0};
    string nombreEspecialidad[maxEspecialidad];
    int usados = 0;


    for (int i = 0; i < cantEsp && usados < maxEspecialidad; i++) {
        Especialidad _especialidad = _repoEspecialidad.leer(i);
        idEsp[usados] = _especialidad.getCodigoEspecialidad();
        nombreEspecialidad[ usados]= _especialidad.getDescripcion();
        usados++;
    }


    for (int i = 0; i < cantTurnos; i++) {
        Turno _turno = _repoTurno.leer(i);

        if (_turno.getEstado()) {

            int codigo = _turno.getCodigoEspecialidad();


            for (int j = 0; j < usados; j++) {
                if (idEsp[j] == codigo) {
                    contador[j]++;
                    break;
                }
            }
        }
    }

    cout << "======================================" << endl;
    cout << "        TURNOS POR ESPECIALIDAD"        << endl;
    cout << "======================================" << endl;

    for (int i = 0; i < usados; i++) {
        cout << nombreEspecialidad[i] << ": " << contador[i] << endl;
    }

}

void ReporteManager::atencionPorObraSocial(){

    int cantidadTurnos = _repoTurno.getCantidadRegistro();
    int cantidad_OS = _repoObrasocial.getCantidadRegistro();

    if (cantidadTurnos == 0) {
        cout << "No hay turnos cargados." << endl;
        return;
    }
    if (cantidad_OS == 0) {
        cout << "No hay obras sociales cargadas." << endl;
        return;
    }

    const int max_OS = 100;
    int idOS[max_OS];
    int cantidadOS[max_OS] = {0};
    float importeOS[max_OS] = {0};
    string nombreObraSocial[max_OS];
    int usados = 0;


    for (int i = 0; i < cantidad_OS && usados < max_OS; i++) {
        ObraSocial _obraSocial = _repoObrasocial.leer(i);
        idOS[usados] = _obraSocial.getIdObraSocial();
        nombreObraSocial[usados] = _obraSocial.getNombre();
        usados++;
    }


    for (int i = 0; i < cantidadTurnos; i++) {

        Turno _turno = _repoTurno.leer(i);


        if (_turno.getEstado()) {

            int codigo = _turno.getIdObraSocial();
            float importe = _turno.getImporteConsulta();


            for (int j = 0; j < usados; j++) {
                if (idOS[j] == codigo) {
                    cantidadOS[j]++;
                    importeOS[j] += importe;
                    break;
                }
            }
        }
    }


    cout << "=============================================" << endl;
    cout << "          ATENCION POR OBRA SOCIAL"            << endl;
    cout << "=============================================" << endl;

    for (int i = 0; i < usados; i++) {

        cout << nombreObraSocial[i]
             << "   Turnos: " << cantidadOS[i]
             << "  | Total facturado: $ " << importeOS[i]
             << endl;
    }
}

void ReporteManager::diagnosticosFrecuentes(){

    int cantidad = _repoHC.getCantidadRegistro();

    if (cantidad == 0) {
        cout << "No hay historias clinicas cargadas." << endl;
        return;
    }

    const int MAX_DIAG = 100;
    string diagnosticos[MAX_DIAG];
    int conteo[MAX_DIAG] = {0};
    int usados = 0;


    for (int i = 0; i < cantidad; i++) {
        HistoriaClinica historiasC = _repoHC.leer(i);

        if (historiasC.getEstado() == true)
        {
            string diag = historiasC.getDiagnostico();
            bool encontrado = false;


            for (int j = 0; j < usados; j++) {
                if (diagnosticos[j] == diag) {
                    conteo[j]++;
                    encontrado = true;
                    break;
                }
            }


            if (!encontrado) {
                diagnosticos[usados] = diag;
                conteo[usados] = 1;
                usados++;
            }
        }
    }


    cout << "============================================="<<endl;
    cout << "DIAGNOSTICOS FRECUENTES EN HISTORIAS CLINICAS"<<endl;
    cout << "============================================="<<endl;
    for (int i = 0; i < usados; i++) {
        cout << diagnosticos[i] << ": " << conteo[i] << " veces"<<endl;
    }
}

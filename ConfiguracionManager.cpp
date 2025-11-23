#include <iostream>
#include "ConfiguracionManager.h"

using namespace std;

    /// BACKUPS
    void ConfiguracionManager::backupTurno(){

    }

    void ConfiguracionManager::backupMedico(){
        MedicoArchivo repoBackup("backups/medicosBackup.dat"); //llamo al constructor y le asigno el nombre

        repoBackup.vaciarArchivo(); //vacio el archivo antes de hacer la copia para que no se dupliquen los registros

        int cantidad = _repoMedico.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay datos para respaladar." << endl;
            return;
        }

        Medico reg;

        for (int i = 0; i < cantidad; i++) { //leo el archivo original y lo gaurdo en el Backup
            reg = _repoMedico.leer(i);
            if(!repoBackup.guardar(reg)){
                cout << "Error al copiar un registro al backup." << endl;
            }
        }

        cout << "Backup creado correctamente" << endl;
    }

    void ConfiguracionManager::backupPaciente(){

    }

    void ConfiguracionManager::backupConsultorio(){
        ConsultorioArchivo repoBackup("backups/consultoriosBackup.dat");

        repoBackup.vaciarArchivo();

        int cantidad = _repoConsultorio.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay datos para respaladar." << endl;
            return;
        }

        Consultorio reg;

        for (int i = 0; i < cantidad; i++) {
            reg = _repoConsultorio.leer(i);
            if(!repoBackup.guardar(reg)){
                cout << "Error al copiar un registro al backup." << endl;
            }
        }

        cout << "Backup creado correctamente" << endl;
    }

    void ConfiguracionManager::backupObraSocial(){
        ObraSocialArchivo repoBackup("backups/obrasSocialesBackup.dat");

        repoBackup.vaciarArchivo();

        int cantidad = _repoObrasocial.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay datos para respaladar." << endl;
            return;
        }

        ObraSocial reg;

        for (int i = 0; i < cantidad; i++) {
            reg = _repoObrasocial.leer(i);
             if(!repoBackup.guardar(reg)){
                cout << "Error al copiar un registro al backup." << endl;
            }
        }

        cout << "Backup creado correctamente." << endl;
    }

    void ConfiguracionManager::backupHistoriaClinica(){

    }

    void ConfiguracionManager::backupEspecialidades(){

    }

    ///RESTAURACIONES

    void ConfiguracionManager::restaurarArchvioTurno(){

    }

    void ConfiguracionManager::restaurarArchvioMedico(){
        MedicoArchivo repoBackup("backups/medicosBackup.dat"); //llamo al constructor y le asigno el nombre

        if(!repoBackup.existe()){
            cout << "El archivo Backup no existe o no se puede abrir" << endl; //verifico que exista el backup
            return;
        }

        int cantidad = repoBackup.getCantidadRegistro();

        if (cantidad == 0) {
            cout << "No hay backup para restaurar." << endl;
            return;
        }

        _repoMedico.vaciarArchivo(); //vacio el archivo antes de restaurarlo

        Medico reg;

        for (int i = 0; i < cantidad; i++) { //leo el Backup y lo guardo en el archivo
            reg = repoBackup.leer(i);
            if(!_repoMedico.guardar(reg)){
                cout << "Error al copiar un registro del backup al archivo." << endl;
            }
        }

        cout << "Restauracion completada." << endl;
    }

    void ConfiguracionManager::restaurarArchvioPaciente(){

    }

    void ConfiguracionManager::restaurarArchvioConsultorio(){
        ConsultorioArchivo repoBackup("backups/consultoriosBackup.dat");

        if(!repoBackup.existe()){
            cout << "El archivo Backup no existe o no se puede abrir" << endl;
            return;
        }

        int cantidad = repoBackup.getCantidadRegistro();

        if (cantidad == 0) {
            cout << "No hay backup para restaurar." << endl;
            return;
        }

        _repoConsultorio.vaciarArchivo();

        Consultorio reg;

        for (int i = 0; i < cantidad; i++) {
            reg = repoBackup.leer(i);
            if(!_repoConsultorio.guardar(reg)){
                cout << "Error al copiar un registro del backup al archivo." << endl;
            }
        }

        cout << "Restauracion completada." << endl;
    }

    void ConfiguracionManager::restaurarArchvioObraSocial(){
        ObraSocialArchivo repoBackup("backups/obrasSocialesBackup.dat");

        if(!repoBackup.existe()){
            cout << "El archivo Backup no existe o no se puede abrir" << endl;
            return;
        }

        int cantidad = repoBackup.getCantidadRegistro();

        if (cantidad == 0) {
            cout << "No hay backup para restaurar." << endl;
            return;
        }

        _repoObrasocial.vaciarArchivo();

        ObraSocial reg;

        for (int i = 0; i < cantidad; i++) {
            reg = repoBackup.leer(i);
            if(!_repoObrasocial.guardar(reg)){
                cout << "Error al copiar un registro del backup al archivo." << endl;
            }
        }

        cout << "Restauracion completada." << endl;
    }

    void ConfiguracionManager::restaurarArchvioHistoriaClinica(){

    }

    void ConfiguracionManager::restaurarArchvioEspecialidades(){

    }

    ///EXPORTACIONES

    void ConfiguracionManager::exportarCSVTurno(){

    }

    void ConfiguracionManager::exportarCSVMedico(){
        FILE *exportar = fopen("csv/medicos.csv", "wt");
        if(exportar == nullptr){
            cout << "No se pudo crear el archivo CSV." << endl;
            return;
        }

        int cantidad = _repoMedico.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros para exportar." << endl;
            fclose(exportar);
            return;
        }

        fprintf(exportar, "ID,DNI,Nombre,Apellido,Telefono,e-mail,Matricula,CodEspecialidad,FechaInicio,Estado\n");

        Medico reg;

        for(int i=0; i<cantidad; i++){
            reg = _repoMedico.leer(i);

             fprintf(exportar, "%d,%s,%s,%s,%s,%s,%s,%d,%d/%d/%d,%d\n",
            reg.getIdMedico(),
            reg.getDniMedico().c_str(),
            reg.getNombreMedico().c_str(),
            reg.getApellidoMedico().c_str(),
            reg.getTelefonoMedico().c_str(),
            reg.getEmailMedico().c_str(),
            reg.getMatricula().c_str(),
            reg.getCodigoEspecialidad(),
            reg.getFechaInicio().getDia(),
            reg.getFechaInicio().getMes(),
            reg.getFechaInicio().getAnio(),
            reg.getEstado()
        );

        }

        fclose(exportar);

        cout << "Archivo CSV exportado correctamente." << endl;
    }

    void ConfiguracionManager::exportarCSVPaciente(){

    }

    void ConfiguracionManager::exportarCSVConsultorio(){
        FILE *exportar = fopen("csv/consultorios.csv", "wt");
        if(exportar == nullptr){
            cout << "No se pudo crear el archivo CSV." << endl;
            return;
        }

        int cantidad = _repoConsultorio.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros para exportar." << endl;
            fclose(exportar);
            return;
        }

        fprintf(exportar, "Numero,Piso,CodEspecialidad,Ocupado,IdMedico,Estado\n");

        Consultorio reg;

        for(int i=0; i<cantidad; i++){
            reg = _repoConsultorio.leer(i);

             fprintf(exportar, "%d,%d,%d,%d,%d,%d\n",
            reg.getNumeroConsultorio(),
            reg.getPisoConsultorio(),
            reg.getCodigoEspecialidad(),
            reg.getOcupado(),
            reg.getIdMedico(),
            reg.getEstado()
            );

        }

        fclose(exportar);

        cout << "Archivo CSV exportado correctamente." << endl;
    }

    void ConfiguracionManager::exportarCSVObraSocial(){
        FILE *exportar = fopen("csv/obrasSociales.csv", "wt");
        if(exportar == nullptr){
            cout << "No se pudo crear el archivo CSV." << endl;
            return;
        }

        int cantidad = _repoObrasocial.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros para exportar." << endl;
            fclose(exportar);
            return;
        }

        fprintf(exportar, "ID,Nombre,Telefono,Estado\n");

        ObraSocial reg;

        for(int i=0; i<cantidad; i++){
            reg = _repoObrasocial.leer(i);

             fprintf(exportar, "%d,%s,%s,%d\n",
            reg.getIdObraSocial(),
            reg.getNombre().c_str(),
            reg.getTelefonoObraSocial().c_str(),
            reg.getEstado()
        );

        }

        fclose(exportar);

        cout << "Archivo CSV exportado correctamente." << endl;
    }

    void ConfiguracionManager::exportarCSVHistoriaClinica(){

    }

    void ConfiguracionManager::exportarCSVEspecialidades(){

    }

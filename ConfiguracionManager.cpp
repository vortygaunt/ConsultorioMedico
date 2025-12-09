#include <iostream>
#include "ConfiguracionManager.h"

using namespace std;

    /// BACKUPS
    void ConfiguracionManager::backupTurno(){
         TurnoArchivo repoBackup("backups/turnosBackup.dat"); //llamo al constructor y le asigno el nombre

        repoBackup.vaciarArchivo(); //vacio el archivo antes de hacer la copia para que no se dupliquen los registros

        int cantidad = _repoTurno.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay datos para respaladar." << endl;
            return;
        }

        Turno reg;

        for (int i = 0; i < cantidad; i++) { //leo el archivo original y lo gaurdo en el Backup
            reg = _repoTurno.leer(i);
            if(!repoBackup.guardar(reg)){
                cout << "Error al copiar un registro al backup." << endl;
            }
        }

        cout << "Backup creado correctamente" << endl;
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
        PacienteArchivo repoBackup("backups/pacientesBackup.dat"); //llamo al constructor y le asigno el nombre

        repoBackup.vaciarArchivo(); //vacio el archivo antes de hacer la copia para que no se dupliquen los registros

        int cantidad = _repoPaciente.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay datos para respaladar." << endl;
            return;
        }

        Paciente reg;

        for (int i = 0; i < cantidad; i++) { //leo el archivo original y lo gaurdo en el Backup
            reg = _repoPaciente.leer(i);
            if(!repoBackup.guardar(reg)){
                cout << "Error al copiar un registro al backup." << endl;
            }
        }

        cout << "Backup creado correctamente" << endl;
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
        HistoriaClinicaArchivo repoBackup("backups/historiasClinicasBackup.dat"); //llamo al constructor y le asigno el nombre

        repoBackup.vaciarArchivo(); //vacio el archivo antes de hacer la copia para que no se dupliquen los registros

        int cantidad = _repoHistoriaClinica.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay datos para respaladar." << endl;
            return;
        }

        HistoriaClinica reg;

        for (int i = 0; i < cantidad; i++) { //leo el archivo original y lo gaurdo en el Backup
            reg = _repoHistoriaClinica.leer(i);
            if(!repoBackup.guardar(reg)){
                cout << "Error al copiar un registro al backup." << endl;
            }
        }

        cout << "Backup creado correctamente" << endl;
    }

    void ConfiguracionManager::backupEspecialidades(){
         EspecialidadArchivo repoBackup("backups/especialidadesBackup.dat"); //llamo al constructor y le asigno el nombre

        repoBackup.vaciarArchivo(); //vacio el archivo antes de hacer la copia para que no se dupliquen los registros

        int cantidad = _repoEspecialidades.getCantidadRegistro();

        if(cantidad == 0){
            cout << "No hay datos para respaladar." << endl;
            return;
        }

        Especialidad reg;

        for (int i = 0; i < cantidad; i++) { //leo el archivo original y lo gaurdo en el Backup
            reg = _repoEspecialidades.leer(i);
            if(!repoBackup.guardar(reg)){
                cout << "Error al copiar un registro al backup." << endl;
            }
        }

        cout << "Backup creado correctamente" << endl;
    }

    ///RESTAURACIONES

    void ConfiguracionManager::restaurarArchvioTurno(){
         TurnoArchivo repoBackup("backups/turnosBackup.dat"); //llamo al constructor y le asigno el nombre

        if(!repoBackup.existe()){
            cout << "El archivo Backup no existe o no se puede abrir" << endl; //verifico que exista el backup
            return;
        }

        int cantidad = repoBackup.getCantidadRegistro();

        if (cantidad == 0) {
            cout << "No hay backup para restaurar." << endl;
            return;
        }

        _repoTurno.vaciarArchivo(); //vacio el archivo antes de restaurarlo

        Turno reg;

        for (int i = 0; i < cantidad; i++) { //leo el Backup y lo guardo en el archivo
            reg = repoBackup.leer(i);
            if(!_repoTurno.guardar(reg)){
                cout << "Error al copiar un registro del backup al archivo." << endl;
            }
        }

        cout << "Restauracion completada." << endl;
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
        PacienteArchivo repoBackup("backups/pacientesBackup.dat"); //llamo al constructor y le asigno el nombre

        if(!repoBackup.existe()){
            cout << "El archivo Backup no existe o no se puede abrir" << endl; //verifico que exista el backup
            return;
        }

        int cantidad = repoBackup.getCantidadRegistro();

        if (cantidad == 0) {
            cout << "No hay backup para restaurar." << endl;
            return;
        }

        _repoPaciente.vaciarArchivo(); //vacio el archivo antes de restaurarlo

        Paciente reg;

        for (int i = 0; i < cantidad; i++) { //leo el Backup y lo guardo en el archivo
            reg = repoBackup.leer(i);
            if(!_repoPaciente.guardar(reg)){
                cout << "Error al copiar un registro del backup al archivo." << endl;
            }
        }

        cout << "Restauracion completada." << endl;
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
        HistoriaClinicaArchivo repoBackup("backups/historiasClinicasBackup.dat"); //llamo al constructor y le asigno el nombre

        if(!repoBackup.existe()){
            cout << "El archivo Backup no existe o no se puede abrir" << endl; //verifico que exista el backup
            return;
        }

        int cantidad = repoBackup.getCantidadRegistro();

        if (cantidad == 0) {
            cout << "No hay backup para restaurar." << endl;
            return;
        }

        _repoHistoriaClinica.vaciarArchivo(); //vacio el archivo antes de restaurarlo

        HistoriaClinica reg;

        for (int i = 0; i < cantidad; i++) { //leo el Backup y lo guardo en el archivo
            reg = repoBackup.leer(i);
            if(!_repoHistoriaClinica.guardar(reg)){
                cout << "Error al copiar un registro del backup al archivo." << endl;
            }
        }

        cout << "Restauracion completada." << endl;
    }

    void ConfiguracionManager::restaurarArchvioEspecialidades(){
         EspecialidadArchivo repoBackup("backups/especialidadesBackup.dat"); //llamo al constructor y le asigno el nombre

        if(!repoBackup.existe()){
            cout << "El archivo Backup no existe o no se puede abrir" << endl; //verifico que exista el backup
            return;
        }

        int cantidad = repoBackup.getCantidadRegistro();

        if (cantidad == 0) {
            cout << "No hay backup para restaurar." << endl;
            return;
        }

        _repoEspecialidades.vaciarArchivo(); //vacio el archivo antes de restaurarlo

        Especialidad reg;

        for (int i = 0; i < cantidad; i++) { //leo el Backup y lo guardo en el archivo
            reg = repoBackup.leer(i);
            if(!_repoEspecialidades.guardar(reg)){
                cout << "Error al copiar un registro del backup al archivo." << endl;
            }
        }

        cout << "Restauracion completada." << endl;
    }

    ///EXPORTACIONES

    void ConfiguracionManager::exportarCSVTurno(){
        FILE *exportar = fopen("csv/turnos.csv", "wt");
        if(exportar == nullptr){
            cout << "No se pudo crear el archivo CSV." << endl;
            return;
        }

        int cantidad = _repoTurno.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros para exportar." << endl;
            fclose(exportar);
            return;
        }

        fprintf(exportar, "ID,DNIPaciente,IDMedico,FechaAtencion,HoraAtencion,ImporteConsulta,NumeroConsultorio,Estado\n");

        Turno reg;

        for(int i=0; i<cantidad; i++){
            reg = _repoTurno.leer(i);

             fprintf(exportar, "%d,%s,%d,%d/%d/%d,%d:%d,%f,%d,%d\n",
            reg.getID(),
            reg.getDniPaciente().c_str(),
            reg.getIdMedico(),
            reg.getFechaAtencion().getDia(),
            reg.getFechaAtencion().getMes(),
            reg.getFechaAtencion().getAnio(),
            reg.getHoraAtencion().getHora(),
            reg.getHoraAtencion().getMinuto(),
            reg.getImporteConsulta(),
            reg.getNumeroConsultorio(),
            reg.getEstado()
        );

        }

        fclose(exportar);

        cout << "Archivo CSV exportado correctamente." << endl;
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
        FILE *exportar = fopen("csv/pacientes.csv", "wt");
        if(exportar == nullptr){
            cout << "No se pudo crear el archivo CSV." << endl;
            return;
        }

        int cantidad = _repoPaciente.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros para exportar." << endl;
            fclose(exportar);
            return;
        }

        fprintf(exportar, "DNI,Nombre,Apellido,Telefono,e-mail,CodObraSocial,FechaNacimiento,Calle,Numero,Localidad,Estado\n");

        Paciente reg;

        for(int i=0; i<cantidad; i++){
            reg = _repoPaciente.leer(i);

             fprintf(exportar, "%s,%s,%s,%s,%s,%d,%d/%d/%d,%s,%d,%s,%d\n",
            reg.getDniPaciente().c_str(),
            reg.getNombrePaciente().c_str(),
            reg.getApellidoPaciente().c_str(),
            reg.getTelefonoPaciente().c_str(),
            reg.getEmailPaciente().c_str(),
            reg.getCodigoObraSocialPaciente(),
            reg.getFechaNacimientoPaciente().getDia(),
            reg.getFechaNacimientoPaciente().getMes(),
            reg.getFechaNacimientoPaciente().getAnio(),
            reg.getDireccionPaciente().getCalle().c_str(),
            reg.getDireccionPaciente().getNumero(),
            reg.getDireccionPaciente().getLocalidad().c_str(),
            reg.getEstadoPaciente()
        );

        }

        fclose(exportar);

        cout << "Archivo CSV exportado correctamente." << endl;
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
        FILE *exportar = fopen("csv/historiasClinicas.csv", "wt");
        if(exportar == nullptr){
            cout << "No se pudo crear el archivo CSV." << endl;
            return;
        }

        int cantidad = _repoHistoriaClinica.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros para exportar." << endl;
            fclose(exportar);
            return;
        }

        fprintf(exportar, "ID,DniPaciente,DniMedico,Fecha,Diagnostico,Observaciones,Tratamiento,IdObraSocial,Estado\n");

        HistoriaClinica reg;

        for(int i=0; i<cantidad; i++){
            reg = _repoHistoriaClinica.leer(i);

            fprintf(exportar, "%d,%s,%s,%d/%d/%d,%s,%s,%s,%d,%d\n",
            reg.getId(),
            reg.getDniPaciente().c_str(),
            reg.getDniMedico().c_str(),
            reg.getFecha().getDia(),
            reg.getFecha().getMes(),
            reg.getFecha().getAnio(),
            reg.getDiagnostico().c_str(),
            reg.getObservaciones().c_str(),
            reg.getTratamiento().c_str(),
            reg.getIdObraSocial(),
            reg.getEstado()
        );

        }

        fclose(exportar);

        cout << "Archivo CSV exportado correctamente." << endl;
    }

    void ConfiguracionManager::exportarCSVEspecialidades(){
         FILE *exportar = fopen("csv/especialidades.csv", "wt");
        if(exportar == nullptr){
            cout << "No se pudo crear el archivo CSV." << endl;
            return;
        }

        int cantidad = _repoEspecialidades.getCantidadRegistro();
        if(cantidad == 0){
            cout << "No hay registros para exportar." << endl;
            fclose(exportar);
            return;
        }

        fprintf(exportar, "CodigoEspecialidad,Descripcion,Estado\n");

        Especialidad reg;

        for(int i=0; i<cantidad; i++){
            reg = _repoEspecialidades.leer(i);

             fprintf(exportar, "%d,%s,%d\n",
            reg.getCodigoEspecialidad(),
            reg.getDescripcion().c_str(),
            reg.getEstado()
        );

        }

        fclose(exportar);

        cout << "Archivo CSV exportado correctamente." << endl;
    }

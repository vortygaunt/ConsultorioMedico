#include <iostream>
#include "PacienteManager.h"
#include "funcionesGlobales.h"

using namespace std;

PacienteManager::PacienteManager(){
}


void PacienteManager::cargar()
{
    bool valido;
    string dniPaciente;
    string nombrePaciente;
    string apellidoPaciente;
    string telefonoPaciente;
    string emailPaciente;
    int codObraSocial;
    Fecha fechaNacimiento;
    PacienteDireccion direcPaciente;

    do{
        cout << "DNI: ";
        dniPaciente = cargarCadena();

        valido = soloDigitos(dniPaciente);

        if (dniPaciente.size() < 7 || dniPaciente.size() > 11) {
            valido = false;
        }
        if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    do{
    cout << "Nombre: ";
    nombrePaciente = cargarCadena();

    valido = soloLetras(nombrePaciente);
    if(!valido){
        cout << "Nombre invalido." << endl;
    }

    }while(!valido);

    do{
    cout << "Apellido: ";
    apellidoPaciente = cargarCadena();

    valido = soloLetras(apellidoPaciente);
    if(!valido){
        cout << "Apellido invalido." << endl;
    }

    }while(!valido);

    do{
    cout << "Telefono: ";
    telefonoPaciente = cargarCadena();

    valido = soloDigitos(telefonoPaciente);

    if (telefonoPaciente.size() < 6 || telefonoPaciente.size() > 15) {
        valido = false;
    }

    if(!valido){
        cout << "Telefono invalido." << endl;
    }

    }while(!valido);


    cout << "Direccion: ";
    direcPaciente.cargar();

    cout << "Email: ";
    emailPaciente = cargarCadena();

    do{
        codObraSocial = leerEntero("Codigo Obra Social: ");
        if (!_obraManager.existeCodigo(codObraSocial)){
                cout << "El codigo ingresado no existe. Intente nuevamente: " << endl;
            }
    } while (!_obraManager.existeCodigo(codObraSocial));


    cout << "Fecha de nacimiento:";
    fechaNacimiento.cargar();


    if(_repo.guardar(Paciente(dniPaciente,nombrePaciente,apellidoPaciente,telefonoPaciente,direcPaciente,emailPaciente,codObraSocial,fechaNacimiento,true)))
    {
         cout << "El paciente se guardo correctamente." << endl;
    }else{
        cout << "Hubo un error al intentar guardar al paciente." << endl;
    }
}


void PacienteManager::modificarTelefono()
{
    string dniBuscado;
    string nuevoTel;
    bool valido;

    do{
    cout << "Ingrese DNI del paciente: ";
    dniBuscado = cargarCadena();

    valido = soloDigitos(dniBuscado);

    if (dniBuscado.size() < 7 || dniBuscado.size() > 11) {
        valido = false;
    }

    if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI." << endl;
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    paciente.mostrar();

    do{
    cout << "Ingrese nuevo telefono: ";
    nuevoTel = cargarCadena();

    valido = soloDigitos(nuevoTel);

    if (nuevoTel.size() < 6 || nuevoTel.size() > 15) {
        valido = false;
    }

    if(!valido){
        cout << "Telefono invalido" << endl;
    }
    }while(!valido);

    paciente.setTelefonoPaciente(nuevoTel);


    if (_repo.modificar(pos, paciente)) {
        cout << "Telefono modificado correctamente.";
    } else {
        cout << "Error al modificar el telefono.";
    }
}

void PacienteManager::modificarDireccion()
{
    string dniBuscado;
    bool valido;

    do{
    cout << "Ingrese DNI del paciente: ";
    dniBuscado = cargarCadena();

    valido = soloDigitos(dniBuscado);

    if (dniBuscado.size() < 7 || dniBuscado.size() > 11){
        valido = false;
    }

    if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI." << endl;
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    paciente.mostrar();


    PacienteDireccion nuevaDir;
    cout << "Ingrese nueva direccion: " << endl;

    nuevaDir.cargar();


    paciente.setDireccionPaciente(nuevaDir);


    if (_repo.modificar(pos, paciente)) {
        cout << "Direccion modificada correctamente.";
    } else {
        cout << "Error al modificar la direccion.";
    }
}

void PacienteManager::modificarEmail()
{
    string dniBuscado;
    string nuevoEmail;
    bool valido;

   do{
    cout << "Ingrese DNI del paciente: ";
    dniBuscado = cargarCadena();

    valido = soloDigitos(dniBuscado);

    if (dniBuscado.size() < 7 || dniBuscado.size() > 11) {
        valido = false;
    }

    if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI." << endl;
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    paciente.mostrar();


    cout << "Ingrese nuevo email: ";
    nuevoEmail = cargarCadena();

    paciente.setEmailPaciente(nuevoEmail);


    if (_repo.modificar(pos, paciente)) {
        cout << "Email modificado correctamente.";
    } else {
        cout << "Error al modificar el email.";
    }
}

void PacienteManager::modificarObraSocial()
{
    string dniBuscado;
    int nuevoCodigo;
    bool valido;

    do{
    cout << "Ingrese DNI del paciente: ";
    dniBuscado = cargarCadena();

    valido = soloDigitos(dniBuscado);

    if (dniBuscado.size() < 7 || dniBuscado.size() > 11) {
        valido = false;
    }

    if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI.";
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    paciente.mostrar();


    do{
    valido = true;

    nuevoCodigo = leerEntero("Ingrese nuevo codigo de obra social: ");

     if (!_obraManager.existeCodigo(nuevoCodigo)) {
        cout << "Código inexistente. Intente nuevamente." << endl;
        valido = false;
    }


    }while(!valido);

    paciente.setCodigoObraSocialPaciente(nuevoCodigo);

    if (_repo.modificar(pos, paciente)) {
        cout << "Obra social modificada correctamente.";
    } else {
        cout << "Error al modificar la obra social.";
    }
}

void PacienteManager::eliminarPaciente()
{
    string dniBuscado;
    bool valido;

    do{
        cout << "Ingrese DNI del paciente: ";
        dniBuscado = cargarCadena();

        valido = soloDigitos(dniBuscado);

        if (dniBuscado.size() < 7 || dniBuscado.size() > 11) {
            valido = false;
        }

        if(!valido){
            cout << "DNI invalido." << endl;
        }

    }while(!valido);

   int pos = _repo.buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI.";
        return;
    }


    Paciente paciente = _repo.leer(pos);

    cout << "Paciente encontrado: " << endl;
    paciente.mostrar();


    /*cout << "¿Desea eliminar este paciente? (S/N): ";
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 'N') {
        cout << "Operación cancelada.";
        return;
    }*/


    paciente.setEstadoPaciente(false);


    if (_repo.modificar(pos, paciente)) {
        cout << "Paciente eliminado correctamente.";
    }
    else {
        cout << "Error al eliminar el paciente.";
    }
}

void PacienteManager::listarOrdenApellido() {
    int cantidad = _repo.getCantidadRegistro();

    if (cantidad == 0) {
        cout << "No hay pacientes cargados." << endl;
        return;
    }

    Paciente* _pacientes;
    _pacientes = new Paciente[cantidad];

    for (int i = 0; i < cantidad; i++) {
        _pacientes[i] = _repo.leer(i);
    }

    for (int i = 0; i < cantidad - 1; i++) {
        bool intercambio = false;

        for (int j = 0; j < cantidad - 1 - i; j++) {
            if (_pacientes[j].getApellidoPaciente() > _pacientes[j + 1].getApellidoPaciente()) {
                Paciente aux = _pacientes[j];
                _pacientes[j] = _pacientes[j + 1];
                _pacientes[j + 1] = aux;
                intercambio = true;
            }
        }
        if (!intercambio) {break;
            }
    }

    for (int i = 0; i < cantidad; i++) {
        if (_pacientes[i].getEstadoPaciente()) {
            _pacientes[i].mostrar();
        }
    }

    delete[] _pacientes;
}

void PacienteManager::listarFechaNacimiento()
{
    int cantidad = _repo.getCantidadRegistro();

    if (cantidad == 0) {
        cout << "No hay pacientes cargados." << endl;
        return;
    }

    Paciente* _pacientes;
    _pacientes = new Paciente[cantidad];

    for (int i = 0; i < cantidad; i++) {
        _pacientes[i] = _repo.leer(i);
    }


    for (int i = 0; i < cantidad - 1; i++) {
        bool intercambio = false;

        for (int j = 0; j < cantidad - 1 - i; j++) {

            Fecha f1 = _pacientes[j].getFechaNacimientoPaciente();
            Fecha f2 = _pacientes[j + 1].getFechaNacimientoPaciente();


            bool debeIntercambiar = false;

            if (f1.getAnio() > f2.getAnio()) {
                debeIntercambiar = true;
            }
            else if (f1.getAnio() == f2.getAnio()) {
                if (f1.getMes() > f2.getMes()) {
                    debeIntercambiar = true;
                }
                else if (f1.getMes() == f2.getMes()) {
                    if (f1.getDia() > f2.getDia()) {
                        debeIntercambiar = true;
                    }
                }
            }

            if (debeIntercambiar) {
                Paciente aux = _pacientes[j];
                _pacientes[j] = _pacientes[j + 1];
                _pacientes[j + 1] = aux;
                intercambio = true;
            }
        }

        if (!intercambio) break;
    }


    for (int i = 0; i < cantidad; i++) {
        if (_pacientes[i].getEstadoPaciente()) {
            _pacientes[i].mostrar();
        }
    }

    delete[] _pacientes;
}

void PacienteManager::listarObraSocial()
{
    int cantidad = _repo.getCantidadRegistro();

    if (cantidad == 0) {
        cout << "No hay pacientes cargados." << endl;
        return;
    }

    Paciente* _pacientes = new Paciente[cantidad];

    for (int i = 0; i < cantidad; i++) {
        _pacientes[i] = _repo.leer(i);
    }

    for (int i = 0; i < cantidad - 1; i++) {
        bool intercambio = false;

        for (int j = 0; j < cantidad - 1 - i; j++) {

            int os1 = _pacientes[j].getCodigoObraSocialPaciente();
            int os2 = _pacientes[j + 1].getCodigoObraSocialPaciente();

            if (os1 > os2) {   // Menor obra social a mayor obra social
                Paciente aux = _pacientes[j];
                _pacientes[j] = _pacientes[j + 1];
                _pacientes[j + 1] = aux;
                intercambio = true;
            }
        }

        if (!intercambio) break;
    }


    for (int i = 0; i < cantidad; i++) {
        if (_pacientes[i].getEstadoPaciente()) {
            _pacientes[i].mostrar();
        }
    }

    delete[] _pacientes;
}

void PacienteManager::consultarDni()
{
    string dniBuscado;
    bool valido;

   do{
    cout << "Ingrese DNI del paciente: ";
    dniBuscado = cargarCadena();

    valido = soloDigitos(dniBuscado);

    if (dniBuscado.size() < 7 || dniBuscado.size() > 11) {
        valido = false;
    }

    if(!valido){
        cout << "DNI invalido." << endl;
    }

    }while(!valido);

    int pos = _repo.buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontro un paciente con ese DNI." << endl;
        return;
    }

    Paciente reg = _repo.leer(pos);
    reg.mostrar();
}

void PacienteManager::consultarObraSocial()
{
    int codigoBuscado;

    int cantidad = _repo.getCantidadRegistro();
    if(cantidad == 0){
        cout << "No hay registros cargados en el archivo." << endl;
        return;
    }

    do{
    codigoBuscado = leerEntero("Ingrese codigo de obra social a buscar: ");
    if(codigoBuscado <= 0){
        cout << "Codigo invalido." << endl;
    }

    }while(codigoBuscado <= 0);


    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Paciente reg = _repo.leer(i);

        if (reg.getEstadoPaciente()) {
            if (reg.getCodigoObraSocialPaciente() == codigoBuscado) {
                if (!encontrado) {
                    cout << "--- PACIENTES CON ESA OBRA SOCIAL ---" << endl;
                }
                reg.mostrar();
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron pacientes con esa obra social." << endl;
    }
}

void PacienteManager::consultarApellidoNombre()
{
    string nombreBuscado, apellidoBuscado;
    bool valido;

    int cantidad = _repo.getCantidadRegistro();
    if(cantidad == 0){
        cout << "No hay registros cargados en el archivo." << endl;
        return;
    }

    do{
    cout << "Ingrese nombre: ";
    nombreBuscado = cargarCadena();

    valido = soloLetras(nombreBuscado);
    if(!valido){
        cout << "Nombre invalido." << endl;
    }

    }while(!valido);

    do{
    cout << "Ingrese apellido: ";
    apellidoBuscado = cargarCadena();

    valido = soloLetras(apellidoBuscado);
    if(!valido){
        cout << "Apellido invalido." << endl;
    }

    }while(!valido);

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Paciente reg = _repo.leer(i);

        if (reg.getEstadoPaciente()) {
            if (reg.getNombrePaciente() == nombreBuscado &&
                reg.getApellidoPaciente() == apellidoBuscado) {

                if (!encontrado) {
                    cout << "--- PACIENTES ENCONTRADOS ---" << endl;
                }

                reg.mostrar();
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron pacientes con ese nombre y apellido."<<endl;
    }
}


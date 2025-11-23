#include <iostream>
#include "PacienteManager.h"
#include "funcionesGlobales.h"

using namespace std;

PacienteManager::PacienteManager(){
}

std::string PacienteManager::cargarCadena()
{
  std::string texto;

  if(std::cin.peek() == '\n')
  {
    std::cin.ignore();
  }

  std::getline(std::cin, texto);

  return texto;
}

void PacienteManager::cargar()
{
    string dniPaciente;
    string nombrePaciente;
    string apellidoPaciente;
    string telefonoPaciente;
    string emailPaciente;
    int codObraSocial;
    Fecha fechaNacimiento;
    PacienteDireccion direcPaciente;

    cout << "DNI: ";
    dniPaciente = cargarCadena();

    cout << "Nombre: ";
    nombrePaciente = cargarCadena();

    cout << "Apellido: ";
    apellidoPaciente = cargarCadena();

    cout << "Telefono: ";
    telefonoPaciente = cargarCadena();

    cout << "Direccion: ";
    direcPaciente.cargar();

    cout << "Email: ";
    emailPaciente = cargarCadena();

    cout << "Codigo Obra Social: ";
    cin >> codObraSocial;
    cin.ignore();

    cout << "Fecha de nacimiento:";
    fechaNacimiento.cargar();


    if(_repo.guardar(Paciente(dniPaciente,nombrePaciente,apellidoPaciente,telefonoPaciente,direcPaciente,emailPaciente,codObraSocial,fechaNacimiento,true)))
    {
         cout << "El paciente se guardo correctamente." << endl;
    }else{
        cout << "Hubo un error al intentar guardar al paciente." << endl;
    }
}

int PacienteManager::buscarPosPorDni(std::string& dniBuscado)
{
    int cantidad = _repo.getCantidadRegistro();

    for (int i = 0; i < cantidad; i++) {
        Paciente reg = _repo.leer(i);

        if (reg.getEstadoPaciente() && reg.getDniPaciente() == dniBuscado) {
            return i;
        }
    }

    return -1; // no encontrado
}

void PacienteManager::modificarTelefono()
{
    string dniBuscado;
    cout << "INGRESE DNI DEL PACIENTE: ";
    cin >> dniBuscado;

    int pos = buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI.";
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    paciente.mostrar();

    string nuevoTel;
    cout << "INGRESE NUEVO TELEFONO: ";
    cin >> nuevoTel;

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
    cout << "INGRESE DNI DEL PACIENTE: ";
    cin >> dniBuscado;

    int pos = buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI.";
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    paciente.mostrar();


    PacienteDireccion nuevaDir;
    cout << "INGRESE NUEVA DIRECCION: ";

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
    cout << "INGRESE DNI DEL PACIENTE: ";
    cin >> dniBuscado;

    int pos = buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI.";
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    paciente.mostrar();


    string nuevoEmail;
    cout << "INGRESE NUEVO EMAIL: ";
    cin >> nuevoEmail;

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
    cout << "INGRESE DNI DEL PACIENTE: ";
    cin >> dniBuscado;

    int pos = buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI.";
        return;
    }

    Paciente paciente = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    paciente.mostrar();

    int nuevoCodigo;
    cout << "INGRESE NUEVO CODIGO DE OBRA SOCIAL: ";
    cin >> nuevoCodigo;

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
    cout << "INGRESE DNI DEL PACIENTE A ELIMINAR: ";
    cin >> dniBuscado;

   int pos = buscarPosPorDni(dniBuscado);
    if (pos == -1) {
        cout << "No se encontró un paciente con ese DNI.";
        return;
    }


    Paciente paciente = _repo.leer(pos);

    cout << "PACIENTE ENCONTRADO: ";
    paciente.mostrar();


    char confirmar;
    cout << "¿DESEA ELIMINAR ESTE PACIENTE? (S/N): ";
    cin >> confirmar;

    if (confirmar != 'S' && confirmar != 's') {
        cout << "Operación cancelada.";
        return;
    }


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
    cout << "INGRESE DNI A BUSCAR: ";
    cin >> dniBuscado;

    int pos = buscarPosPorDni(dniBuscado);

    if (pos == -1) {
        cout << "No se encontro un paciente con ese DNI.";
        return;
    }

    Paciente reg = _repo.leer(pos);
    reg.mostrar();
}

void PacienteManager::consultarObraSocial()
{
    int codigoBuscado;
    cout << "INGRESE CODIGO DE OBRA SOCIAL A BUSCAR: ";
    cin >> codigoBuscado;

    int cantidad = _repo.getCantidadRegistro();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Paciente reg = _repo.leer(i);

        if (reg.getEstadoPaciente()) {
            if (reg.getCodigoObraSocialPaciente() == codigoBuscado) {
                if (!encontrado) {
                    cout << "--- PACIENTES CON ESA OBRA SOCIAL ---";
                }
                reg.mostrar();
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "No se encontraron pacientes con esa obra social.";
    }
}

void PacienteManager::consultarApellidoNombre()
{
    string nombreBuscado, apellidoBuscado;

    cout << "INGRESE NOMBRE: ";
    cin >> nombreBuscado;

    cout << "INGRESE APELLIDO: ";
    cin >> apellidoBuscado;

    int cantidad = _repo.getCantidadRegistro();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Paciente reg = _repo.leer(i);

        if (reg.getEstadoPaciente()) {
            if (reg.getNombrePaciente() == nombreBuscado &&
                reg.getApellidoPaciente() == apellidoBuscado) {

                if (!encontrado) {
                    cout << "--- PACIENTES ENCONTRADOS ---";
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

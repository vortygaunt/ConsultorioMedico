#include <iostream>
#include "funcionesGlobales.h"

using namespace std;

string cargarCadena(){
    string texto;

    if(cin.peek() == '\n'){
        cin.ignore();
    }

    getline(cin, texto);

    return texto;
}


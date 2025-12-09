#include <iostream>
#include <cctype>
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

bool soloDigitos(string &str){
    int tamanio = str.size();

    if(tamanio == 0){
        return false;
    }

    for(int i = 0; i < tamanio; i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

bool soloLetras(string &str){
    int tamanio = str.size();

    if(tamanio == 0){
        return false;
    }

    for(int i = 0; i < tamanio; i++){
        if(!isalpha(str[i]) && str[i] != ' '){
            return false;
        }
    }
    return true;
}

int leerEntero(const string &mensaje){
    int valor;

    cout << mensaje;
    while(!(cin >> valor)){
        cout << "Valor invalido. Intente nuevamente." << endl;

        cin.clear();
        cin.ignore(10000, '\n');

        cout << mensaje;
    }
    return valor;
}

float leerFloat(const string &mensaje){
    float valor;

    cout << mensaje;
    while(!(cin >> valor)){
        cout << "Valor invalido. Intente nuevamente." << endl;

        cin.clear();
        cin.ignore(10000, '\n');

        cout << mensaje;
    }
    return valor;
}

bool soloDigitosyLetras(string &str){
    int tamanio = str.size();

    if(tamanio == 0){
        return false;
    }

    for(int i = 0; i < tamanio; i++){

        // Permite letras, números y espacio
        if(!isalnum(str[i]) && str[i] != ' '){
            return false;
        }
    }

    return true;
}


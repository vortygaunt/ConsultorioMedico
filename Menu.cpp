#include <iostream>
#include "Menu.h"
#include "funcionesGlobales.h"

using namespace std;

    Menu::Menu(){
        _cantidadOpciones = 1;
    }

    void Menu::mostrar(){
        int opcion;

        do{
            system("cls");
            opcion = seleccionarOpciones();
            system("cls");
            ejecutarOpciones(opcion);
            if(opcion != 0){
             system("pause");
            }
        }while(opcion != 0);

    }

     void Menu::mostrarOpciones(){
        cout << "****** MENU GENERICO ******" << endl;
        cout << "0 . VOLVER" << endl;
        cout << "*************************" << endl;

    }


    int Menu::seleccionarOpciones(){
        int opcion;

        mostrarOpciones();

        opcion = leerEntero("Seleccionar opcion: ");

        while(opcion < 0 || opcion > _cantidadOpciones){
            cout << "Opcion incorrecta vuelva a elegir" << endl;
            opcion = leerEntero("Seleccionar opcion: ");
        }

        return opcion;

    }

      void Menu::ejecutarOpciones(int opcion){
         switch(opcion){


        }

    }



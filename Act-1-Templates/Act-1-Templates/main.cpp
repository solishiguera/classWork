//
//  main.cpp
//  Act-1-Templates
//
//  Created by Diego Solis on 8/10/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <array>
#include "Lista.h"

int main() {
    char opcion = 'q';
    Lista<int> listaNum;
    
    while (opcion != 'f') {
        cout << "a) Insertar valor "<< endl;
        cout << "b) Eliminar dato "<< endl;
        cout << "c) Imprimir dato de casilla "<< endl;
        cout << "d) Imprimir tamaño "<< endl;
        cout << "e) Imprimir arreglo "<< endl;
        cout << "f) Salir "<< endl;
        cout << "Opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 'a': {
                int dato;
                cout << "Teclea el valor del dato que desee insertar: ";
                cin >> dato;
                try {
                    listaNum.insert(dato);
                } catch (runtime_error& e){
                    cout << e.what() << endl;
                }
            }
                break;
                
            case 'b': {
                try {
                    listaNum.erase();
                } catch (runtime_error& e){
                    cout << e.what() << endl;
                }
                break;
            }
            case 'c': {
                int numCasilla;
                cout << "Teclea el valor de la casilla: ";
                cin >> numCasilla;
                try {
                    cout << "El valor es: " << listaNum.getData(numCasilla) << endl;
                } catch (runtime_error& e){
                    cout << e.what() << endl;
                }
                break;
            }
            case 'd': {
                cout << "El tamaño del arreglo es: " << listaNum.getSize() << endl;
                break;
            }
            case 'e': {
                listaNum.print();
                break;
            }
        }
        cout << endl;
        
    }
    return 0;
}

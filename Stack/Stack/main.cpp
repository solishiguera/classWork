//
//  main.cpp
//  Stack
//
//  Created by Diego Solis on 10/17/20.
//

#include <iostream>
using namespace std;
#include "Stack.h"

template<class T>
void generaLista(Stack<T> &pila, string type) {
    T dato;
    int cant;
    cout << endl << "Cuantos datos deseas?: ";
    cin >> cant;
    
    for (int i = 0; i < cant; i++) {
        cout << "Teclea " << type << " " << i + 1 << ": ";
        cin >> dato;
        pila.push(dato);
    }
}

template<class T>
void menuOpciones(Stack<T> pila) {
    int opcion = 10;
    int lastOption;
    while(opcion != 7) {
        lastOption = opcion;
        cout << endl;
        cout << "Lista de opciones" << endl;
        cout << "1) Agregar dato (Push)" << endl;
        cout << "2) Eliminar dato de inicio (Pop)" << endl;
        cout << "3) Obtener último dato agregado (Top)" << endl;
        cout << "4) Obtener tamaño de queue" << endl;
        cout << "5) Limpiar fila" << endl;
        cout << "6) Imprimir datos" << endl;
        cout << "7) Salir" << endl;
        cout << "Teclea la opción que desees: ";
        cin >> opcion;
        pila.printElements();
        
        switch (opcion) {
            case 1: { // Agregar dato
                T data;
                cout << "Teclea el dato que desees agregar: ";
                cin >> data;
                pila.push(data);
                pila.printElements();
                break;
            }
            case 2: { // Eliminar dato
                try {
                    pila.pop();
                } catch(out_of_range& e) {
                    e.what();
                }
                pila.printElements();
                break;
            }
            case 3: { // Obtener último dato agregado (Top)
                try {
                    cout << "El último dato agregado es " << pila.top() << endl;
                } catch(out_of_range& e) {
                    e.what();
                }
                pila.printElements();
                break;
            }
            case 4: { // Obtener tamaño de Stack
                cout << "La pila contiene " << pila.getSize() << " elementos" << endl;
                break;
            }
            case 5: { // Limpiar fila
                pila.clear();
                pila.printElements();
                cout << "La pila está vacía ^^" << endl;
                break;
            }
            case 6: { // Imprimir datos
                pila.printElements();
                break;
            }
        }
    }
}

int main() {
    Stack<int> intList;
    Stack<char> charList;
    Stack<string> strList;
    int opcionLista = 5;
    cout << "Bienvenid@!" << endl;
    
    cout << "Qué tipo de datos deseas que contenga tu LinkedList? " << endl;
    cout << "1) Números enteros" << endl;
    cout << "2) Caracteres" << endl;
    cout << "3) Strings" << endl;
    cout << "Teclea la opción que desees: ";
    cin >> opcionLista;
    
    switch (opcionLista) {
        case 1: {
            generaLista<int>(intList, "entero");
            menuOpciones<int>(intList);
            break;
        }
        case 2: {
            generaLista<char>(charList, "caracter");
            menuOpciones<char>(charList);
            break;
        }
        case 3:{
            generaLista<string>(strList, "palabra");
            menuOpciones<string>(strList);
            break;
        }
        default:
            break;
    }
    return 0;
}

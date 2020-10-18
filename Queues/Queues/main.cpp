//
//  main.cpp
//  Queues
//
//  Created by Diego Solis on 10/17/20.
//

#include <iostream>
using namespace std;
#include "Queue.h"

/*
 Git
 cd Documents/TEC/"SEMESTRE 3"/"Estructura de datos"/classWork
 */

template<class T>
void generaLista(Queue<T> &fila, string type) {
    T dato;
    int cant;
    cout << endl << "Cuantos datos deseas?: ";
    cin >> cant;
    
    for (int i = 0; i < cant; i++) {
        cout << "Teclea " << type << " " << i + 1 << ": ";
        cin >> dato;
        fila.enqueue(dato);
    }
}

template<class T>
void menuOpciones(Queue<T> fila) {
    int opcion = 10;
    int lastOption;
    while(opcion != 8) {
        lastOption = opcion;
        cout << endl;
        cout << "Lista de opciones" << endl;
        cout << "1) Agregar dato (Enqueue)" << endl;
        cout << "2) Eliminar dato de inicio (Dequeue)" << endl;
        cout << "3) Obtener dato de inicio" << endl;
        cout << "4) Obtener dato final" << endl;
        cout << "5) Obtener tamaño de queue" << endl;
        cout << "6) Limpiar fila" << endl;
        cout << "7) Imprimir datos" << endl;
        cout << "8) Salir" << endl;
        cout << "Teclea la opción que desees: ";
        cin >> opcion;
        fila.printElements();
        
        switch (opcion) {
            case 1: { // Dato al principio
                T data;
                cout << "Teclea el dato que desees agregar: ";
                cin >> data;
                fila.enqueue(data);
                fila.printElements();
                break;
            }
            case 2: { // Eliminar dato de inicio
                fila.dequeue();
                fila.printElements();
                break;
            }
            case 3: { // Obtener dato de inicio
                try {
                    cout << "El dato inicial es " << fila.front() << endl;
                } catch(out_of_range& e) {
                    e.what();
                }
                fila.printElements();
                break;
            }
            case 4: { // Obtener dato final
                try {
                    cout << "El dato final es " << fila.back() << endl;
                } catch(out_of_range& e) {
                    e.what();
                }
                fila.printElements();
                break;
            }
            case 5: { // Obtener tamaño de queue
                cout << "La fila contiene " << fila.getSize() << " elementos" << endl;
                break;
            }
            case 6: { // Limpiar fila
                fila.clear();
                fila.printElements();
                cout << "La fila está vacía ^^" << endl;
                break;
            }
            case 7: { // Imprimir datos
                fila.printElements();
                break;
            }
        }
    }
}



int main() {
    Queue<int> intList;
    Queue<char> charList;
    Queue<string> strList;
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

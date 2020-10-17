//
//  main.cpp
//  Linked-List
//
//  Created by Diego Solis on 10/17/20.
//

#include <iostream>
using namespace std;
#include "Queue.h"
#include "LinkedList.h"

/*
 Git
 cd Documents/TEC/"SEMESTRE 3"/"Estructura de datos"/classWork
 */

template<class T>
void generaLista(LinkedList<T> &lista, string type) {
    T dato;
    int cant;
    cout << endl << "Cuantos datos deseas?: ";
    cin >> cant;
    
    for (int i = 0; i < cant; i++) {
        cout << "Teclea " << type << " " << i + 1 << ": ";
        cin >> dato;
        lista.addLast(dato);
    }
}

template<class T>
void menuOpciones(LinkedList<T> lista) {
    int opcion = 10;
    while(opcion != 9) {
        cout << endl;
        cout << "Lista de opciones" << endl;
        cout << "0) Ordenar lista" << endl;
        cout << "1) Agregar dato al principio" << endl;
        cout << "2) Agregar dato al final" << endl;
        cout << "3) Eliminar un dato" << endl;
        cout << "4) Eliminar un dato en posición determinada" << endl;
        cout << "5) Obtener dato de posición determinada" << endl;
        cout << "6) Actualizar dato en posición determinada" << endl;
        cout << "7) Actualizar dato" << endl;
        cout << "8) Buscar dato" << endl;
        cout << "9) Salir" << endl;
        cout << "Teclea la opción que desees: ";
        cin >> opcion;
        lista.printElements();
        
        switch (opcion) {
            case 0: { // Ordenar lista
                lista.sort();
                lista.printElements();
                break;
            }
            case 1: { // Dato al principio
                T data;
                cout << "Teclea el dato que desees agregar: ";
                cin >> data;
                lista.addFirst(data);
                lista.printElements();
                break;
            }
            case 2: { // Dato al final
                T data;
                cout << "Teclea el dato que desees agregar: ";
                cin >> data;
                lista.addLast(data);
                lista.printElements();
                break;
            }
            case 3: { // Eliminar dato
                T data;
                cout << "Qué dato deseas eliminar?: ";
                cin >> data;
                try {
                    lista.deleteData(data);
                } catch(out_of_range& e) {
                    e.what();
                }
                lista.printElements();
                break;
            }
            case 4: { // Eliminar en posición
                int index;
                cout << "Teclea la posición que desees eliminar: ";
                cin >> index;
                try {
                    lista.deleteAt(index);
                } catch(out_of_range& e) {
                    e.what();
                }
                lista.printElements();
                break;
            }
            case 5: { // Obtener dato de posición determinada
                int index;
                cout << "Teclea la posición: ";
                cin >> index;
                try {
                    cout << "El dato en la posición " << index << " es " << lista[index] << endl;
                } catch(out_of_range& e) {
                    e.what();
                }
                lista.printElements();
                break;
            }
            case 6: { // Actualizar dato en posición determinada
                T data;
                int index;
                cout << "Teclea la posición que desees actualizar: ";
                cin >> index;
                cout << "Teclea el nuevo dato: ";
                cin >> data;
                try {
                    lista.updateAt(index, data);
                } catch(out_of_range& e) {
                    e.what();
                }
                lista.printElements();
                break;
            }
            case 7: { // Actualizar dato
                T data, newData;
                cout << "Teclea el dato que desees actualizar: ";
                cin >> data;
                cout << "Teclea dato nuevo: ";
                cin >> newData;
                lista.updateData(data, newData);
                lista.printElements();
                break;
            }
            case 8: { // Buscar dato
                T data;
                cout << "Qué dato deseas buscar?: ";
                cin >> data;
                lista.sort();
                try {
                    int place = lista.findData(data);
                    cout << "El dato se encuentra en la posición " << place << endl;
                } catch(out_of_range& e) {
                    e.what();
                }
                lista.printElements();
                break;
            }
            default: {
                break;
            }
        }
    }
}


int main() {
    LinkedList<int> intList;
    LinkedList<char> charList;
    LinkedList<string> strList;
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

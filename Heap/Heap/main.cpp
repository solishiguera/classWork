//
//  main.cpp
//  Heap
//
//  Created by Diego Solis on 10/19/20.
//

/*
 Git
 cd Documents/TEC/"SEMESTRE 3"/"Estructura de datos"/classWork
 */

#include <iostream>
using namespace std;
#include "Heap.h"



int main() {
    int opcion = 0;
    DoublyLinkedList<int> list;
    list = {12,3,51,1,5,8,2,7};
    Heap<int> myHeap(list);
    cout << "Doubly Linked list para Heap: ";
    list.print();
    while (opcion != 5) {
        Heap<int> myHeap(list);
        cout << endl;
        cout << "Menú de opciones: " << endl;
        cout << "1) Insertar dato en Heap " << endl;
        cout << "2) Eliminar dato en Heap" << endl;
        cout << "3) Realizar HeapSort" << endl;
        cout << "4) Mostrar Heap" << endl;
        cout << "5) Salir" << endl;
        cout << "Teclea opción: ";
        cin >> opcion;
        
        
        switch (opcion) {
            case 1: {
                int data;
                cout << "Teclea el dato que desees agregar: ";
                cin >> data;
                myHeap.insertElement(data);
                myHeap.print();
                break;
            }
            case 2: {
                myHeap.remove();
                myHeap.print();
                break;
            }
            case 3: {
                int opc;
                cout << endl;
                cout << "Teclea la forma de realizar el sort: " << endl;
                cout << "1) Ascendiente" << endl;
                cout << "2) descendiente" << endl;
                cout << "Teclea opción: ";
                cin >> opc;
                
                switch (opc) {
                    case 1: {
                        HeapSort(list);
                        list.print();
                        break;
                    }
                    case 2: {
                        HeapSort(list, "Descending");
                        list.print();
                        break;
                    }
                    default:
                        break;
                }
                
                break;
            }
            case 4: {
                myHeap.print();
                break;
            }
            default:
                break;
        }
    }
    
    return 0;
}


/*
 int main() {
 DoublyLinkedList<int> list;
 list = {8,5,17,19,21,28};
 //list.print();
 
 Heap<int> heap(list);
 
 //heap.print();
 //heap.insertElement(9);
 HeapSort(list, "descending");
 cout << "Descending" << endl;
 list.print();
 cout << endl << "ascending" << endl;
 HeapSort(list);
 list.print();
 heap.print();
 try {
 cout << "The number: " << heap.remove() << " from heap" << endl;
 cout << "The number: " << heap.remove() << " from heap" << endl;
 cout << "The number: " << heap.remove() << " from heap" << endl;
 cout << "The number: " << heap.remove() << " from heap" << endl;
 cout << "The number: " << heap.remove() << " from heap" << endl;
 cout << "The number: " << heap.remove() << " from heap" << endl;
 cout << "The number: " << heap.remove() << " from heap" << endl;
 } catch (runtime_error& e) {
 e.what();
 }
 return 0;
 }
 */

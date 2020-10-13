//
//  main.cpp
//  BinarySearchTrees
//
//  Created by Diego Solis on 10/9/20.
//

/*
GIT
cd Documents/TEC/"SEMESTRE 3"/"Estructura de datos"/classWork
*/

#include <iostream>
using namespace std;
#include "Node.h"
#include "BST.h"

int main() {
    int opcion = 0;
    BST<int> myBSTree;
    myBSTree.insert(9);
    myBSTree.insert(7);
    myBSTree.insert(11);
    myBSTree.insert(6);
    myBSTree.insert(8);
    myBSTree.insert(13);
    
    myBSTree.print();
    
    while (opcion != 5) {
        cout << "1. Insertar elemento" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Eliminar elemento" << endl;
        cout << "4. Imprimir BST" << endl;
        cout << "5. Salir" << endl;
        cout << "Teclea una opción: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1: {
                int dato = 0;
                cout << "Teclea el número que desees insertar: ";
                cin >> dato;
                cout << "~~~~~BST Antes~~~~~" << endl;
                myBSTree.print();
                myBSTree.insert(dato);
                cout << "~~~~~BST Después~~~~~" << endl;
                myBSTree.print();
                break;
            }
            case 2: {
                int buscar = 0;
                cout << "Teclea el número que desees buscar: ";
                cin >> buscar;
                bool yes = false;
                try {
                    yes = myBSTree.find(buscar);
                } catch (out_of_range& e) {
                    cout << e.what() << endl;
                }
                
                if(yes) {
                    cout << "Sí se encontró el número " << buscar << " en la estructura de datos" << endl;
                }
                break;
            }
            case 3: {
                int dato = 0;
                cout << "Teclea el número que desees eliminar: ";
                cin >> dato;
                cout << "~~~~~BST Antes~~~~~" << endl;
                myBSTree.print();
                myBSTree.removeElement(dato);
                cout << "~~~~~BST Después~~~~~" << endl;
                myBSTree.print();
                break;
            }
            case 4: {
                myBSTree.print();
                break;
            }
            case 5: {
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

//
//  main.cpp
//  Heap
//
//  Created by Diego Solis on 10/19/20.
//

#include <iostream>
using namespace std;
#include "Heap.h"

int main() {
    DoublyLinkedList<int> list;
    list = {8,5,17,19,21,28};
    
    list.print();
    
    Heap<int> heap(list);
    heap.print();
    
    /*
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
     */
}

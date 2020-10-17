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

int main() {
    LinkedList<int> myList;
    myList.addLast(4);
    myList.addLast(3);
    myList.addLast(7);
    myList.addLast(1);
    myList.addLast(2);
    myList.addFirst(12);
    myList.printElements();
    myList.printElements();
    
    return 0;
}

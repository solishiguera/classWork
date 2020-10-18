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

int main() {
    Queue<int> fila;
    fila.enqueue(4);
    fila.enqueue(2);
    fila.enqueue(6);
    fila.enqueue(7);
    fila.enqueue(9);
    fila.enqueue(1);
    
    fila.printElements();
    fila.dequeue();
    fila.clear();
    fila.printElements();
    return 0;
}

//
//  main.cpp
//  Hashing
//
//  Created by Diego Solis on 11/30/20.
//

#include <iostream>
using namespace std; 
#include <vector>
#include "HashQ.h"

int hashing(string data, int &key, int size) {
    // key = (unsigned char) data[0]; // Regresa ascii extendido
    // key = int(data[0]); // Regresa el código ascii
    int index;
    
    // Función hashing
    for(auto c : data) { // Sumar el valor ascii de todas las letras de palabra
        key += (unsigned char) c;
    }
    
    
    return key % size; // Size es 53, número primo más cercano a 50
}

int main() {
    string data;
    cout << "Teclea una palabra de máximo cuatro letras: ";
    cin >> data;
    
    int key;
    int size = 53;
    int index = hashing(data, key, size);
    cout << "La llave es: " << key << ", el índice es: " << index << endl;
    
    
    return 0;
}

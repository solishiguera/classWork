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

int hashing(string data, int &key) {
    key = (unsigned char) data[0]; // Regresa ascii extendido
    // key = int(data[0]); // Regresa el código ascii
    int index;
    // Función hashing
    
    return index;
}

int main() {
    string data;
    cout << "Teclea una palabra de máximo cuatro letras: ";
    cin >> data;
    
    int key;
    int index = hashing(data, key);
    cout << "La llave es: " << key << ", el índice es: " << index << endl;
    
    
    return 0;
}

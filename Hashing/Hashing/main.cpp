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

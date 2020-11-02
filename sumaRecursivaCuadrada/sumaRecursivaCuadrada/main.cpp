//
//  main.cpp
//  sumaRecursivaCuadrada
//
//  Created by Diego Solis on 8/26/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
using namespace std;

// Diego Solis Higuera
// A00827847
// Complejidad: O(n)

int sumaRecursivaCuadrada(int numero)
{
    if(numero == 1) {
        return 1;
    } else {
        return numero * numero + sumaRecursivaCuadrada(numero-1);
    }
}


int main() {
    int n = 4;
    cout << sumaRecursivaCuadrada(n) << endl;
    return 0;
}

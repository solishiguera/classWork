//
//  main.cpp
//  Act-4.1.1
//
//  Created by Diego Solis on 11/2/20.
//

#include <iostream>
using namespace std;
#include <vector>
#include "GrafoLista.h"

/*
 Git
 cd Documents/TEC/"SEMESTRE 3"/"Estructura de datos"/classWork
 */

// Usar vectores, Dos clases

int main() {
    vector< vector<int> > listaAd = {{1,2,3,4}, {2,1,3}, {3,4}};
    GrafoLista<int> hola(listaAd, 8,8);
    hola.printListaAdy();
    
    
    return 0;
}

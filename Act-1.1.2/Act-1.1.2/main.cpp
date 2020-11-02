//
//  main.cpp
//  Act-1.1.2
//
//  Created by Diego Solis on 8/31/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <string>
#include <map>

void cargaArchivoCaracteres(vector<string> &vectorStrings, int &cantElementos) {
    ifstream archivoCaracteres;
    string charPegados;
    archivoCaracteres.open("datos.txt");
    
    archivoCaracteres >> cantElementos;
    while(archivoCaracteres >> charPegados) {
        vectorStrings.push_back(charPegados);
    }
    
    archivoCaracteres.close();
}

// TERMINAR
/*
int busqSecuencial(string charPegados, int &comparaciones) {
    for (int i = 1; i < charPegados.size(); i++) {
        comparaciones++;
        if (charPegados[i-1] != charPegados[i] && charPegados[i] != ) {
            return i;
        }
    }
    throw runtime_error("No se encontró el dato buscado");
}

int busqBinaria(string charPegados) {
    int centro, inferior, superior, valorCentral, sizeLista;
    inferior = 0;
    sizeLista = (int) charPegados.size();
    superior = sizeLista - 1;
    
    while (inferior <= superior) {
        centro = (inferior + superior) / 2;
        valorCentral = charPegados[centro];
        if (valorCentral != charPegados[centro+1] && valorCentral != charPegados[centro-1]) {
            return centro;
        } else if(valorCentral == charPegados[centro - 1]) {
            inferior = centro + 1;
        } else {
            superior = centro - 1;
        }
    }
    return 0;
}
*/
char busquedaSecuencial(string linea, int &comparaciones) {
    comparaciones = 0;
    for (int i = 0; i < linea.size(); i++) {
        comparaciones++;
        if (i == 0) {
            comparaciones++;
            if (linea[i+1] != linea[i]) {
                return linea[i];
            }
        } else if (i == linea.size()-1) {
            comparaciones++;
            if (linea[i-1] != linea[i]) {
                return linea[i];
            }
        } else if (linea[i-1] != linea[i] && linea[i+1] != linea[i]) {
            comparaciones++;
            return linea[i];
        }
    }
    return ' ';
}

char busqBinaria(string linea, int &comparaciones) {
    comparaciones = 0;
    int inicio = 0;
    int fin = (int) linea.size()-1;
    int centro;
    while (inicio <= fin) {
        comparaciones++;
        centro = (inicio + fin)/2;
        comparaciones++;
        if (linea[centro] != linea[centro+1] && linea[centro] != linea[centro-1]) {
            return linea[centro];
        
        } else if (linea[centro] == linea[centro+1]) {
            comparaciones++;
            if (centro % 2 == 0) {
                comparaciones++;
                inicio = centro + 1;
            } else {
                comparaciones++;
                fin = centro -1;
            }
        } else if (linea[centro] == linea[centro-1]) {
            comparaciones++;
            if (centro % 2 == 0) {
                comparaciones++;
                fin = centro -1;
            } else {
                comparaciones++;
                inicio = centro + 1;
            }
        }
    }
    return ' ';
}

void imprimeMapa(map<char, int> mapita) {
    int comparaciones = 0;
    
    for (const auto& x : mapita) {
        
        comparaciones++;
        if(x.second == 1) {
            cout << x.first << " - Comparaciones: "<< comparaciones << endl;
        }
    }
}

void separaEnMapas(map<char, int> &mapita, vector<string> arreglo, int cantElementos) {
    string actual = "";
    
    for (int i = 0; i < cantElementos; i++) {
        actual = arreglo.at(i);
        for (int j = 0; j < actual.size(); j++) {
            mapita[actual.at(j)] += 1;
        }
        
        imprimeMapa(mapita);
        mapita.clear();
    }
}


int main() {
    vector<string> vectorStrings;
    map<char, int> mapita;
    int cantElementos = 0, comparaciones = 0;
    char unico;
    
    cargaArchivoCaracteres(vectorStrings, cantElementos);
    //separaEnMapas(mapita, vectorStrings, cantElementos);
    
    for (int i = 0; i < vectorStrings.size(); i++) {
        unico = busqBinaria(vectorStrings[i], comparaciones);
        cout << unico << endl;
    }

    return 0;
}

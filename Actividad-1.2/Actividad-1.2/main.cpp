//
//  main.cpp
//  Act-1.2
//
//  Created by Diego Solis on 8/20/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;
//#include"Timer.h"
#include "Fraccion.h"

// ordenaIntercambio
// ordenaBurbuja
// ordenaMerge NO LO TENGO
// busqSecuencial
// busqBinaria 


template<class T>
void cambia(vector<T> &lista, int a, int b) {
    T aux = lista[a];
    lista[a] = lista[b];
    lista[b] = aux;
}

template<class T>
vector<T> intercambio(vector<T> lista, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 0; i < lista.size(); i++) {
        for (int j = i + 1; j < lista.size(); j++) {
            comparaciones++;
            if (lista[i] > lista[j]) {
                intercambios++;
                cambia(lista,i,j);
            }
        }
    }
    return lista;
}

template<class T>
vector<T> burbuja(vector<T> lista, int &comparaciones, int &intercambios) {
    
    comparaciones = 0;
    intercambios = 0;
    
    bool cambio = true;
    for (int i = 0; i < lista.size() - 1; i++) {
        cambio = false;
        for (int j = 0; j < lista.size() - i - 1  && cambio; j++) {
            comparaciones++;
            if (lista[j] > lista[j+1]) {
                intercambios++;
                cambia(lista, j, j+1);
                cambio = true;
            }
        }
    }
    return lista;
}


template<class T>
int busqSecuencial(vector<T> lista, int &comparaciones, T datoPerdido) {
    for (int i = 0; i < lista.size(); i++) {
        if(lista[i] == datoPerdido) {
            comparaciones++;
            return i;
        }
        
        comparaciones++;
    }
    throw runtime_error("No se encontró el dato buscado");
}

template <class T>
vector<T> busqBinaria(vector<T> lista, int &comparaciones, T data) {
    int centro, inferior, superior, valorCentral, sizeLista;
    inferior = 0;
    sizeLista = lista.size();
    superior = sizeLista - 1;
    
    while (inferior <= superior) {
        centro = (inferior + superior) / 2;
        valorCentral = lista[centro];
        if (data == valorCentral) {
            return centro;
        } else if(data < valorCentral) {
            superior = centro - 1;
        } else {
            inferior = centro + 1;
        }
    }
    throw runtime_error("No se encontró el dato buscado");
    
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
void imprimir(vector<T> lista) {
    for (int i=0;i<lista.size(); i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

void creaListaEO(vector<int> &lista, int cantidad) {
    lista.clear();
    for (int i=0; i<cantidad; i++) {
        lista.push_back(rand() % 100 + 1);
    }
}

void creaListaCO(vector<char> &lista, int cantidad) {
    lista.clear();
    int r;
    for (int i=0; i<cantidad; i++) {
        r = rand() % 26;
        lista.push_back('a' + r);
    }
}

void creaListaFO(vector<Fraccion> &lista, int cantidad) {
    lista.clear();
    int numerador, denominador;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea el numerador: " << endl;
        cin >> numerador;
        cout << "Teclea el denominador: " << endl;
        cin >> denominador;
        lista.push_back(Fraccion(numerador,denominador));
    }
}

void creaListaSO(vector<string> &lista, int cantidad) {
    lista.clear();
    string valor;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea una palabra: " << endl;
        cin >> valor;
        lista.push_back(valor);
    }
}

void calculaTiempo(struct timeval begin, struct timeval end) {
    long seconds, microseconds;
    double elapsed;
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}

void creaListaOrdenada(vector<int> &listaOrdenada, int inferior, int superior) {
    listaOrdenada.clear();
    for (int i = inferior; i <= superior; i++) {
        listaOrdenada.push_back(i);
    }
}

int main()
{
    int cant,comparaciones, intercambios;
    struct timeval begin, end;
    vector<int> listaEO;
    vector<int> listaE;
    vector<Fraccion> listaFO;
    vector<Fraccion> listaF;
    vector<char> listaCO;
    vector<char> listaC;
    vector<string> listaSO;
    vector<string> listaS;
    char tipo = 'e';
    
    char op='a';
    while (op != 'z') {
        cout << endl;
        cout << "Menu" << endl;
        cout << "a) Selecciona tipo de dato para crear la lista" << endl;
        cout << "b) Orden por Intercambio" << endl;
        cout << "c) Orden por Burbuja" << endl;
        cout << "d) Orden por Merge" << endl;
        cout << "e) Búsqueda Secuencial" << endl;
        cout << "f) Búsueda Binaria (Solo números enteros)" << endl;
        cout << "g) Comparar tiempor de ejecución de algoritmos de ordenamiento" << endl;
        cout << "z) salir" << endl;
        cout << endl << "Teclea una opción: ";
        cin >> op;
        
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        switch (op) {
            case 'a':
                cout << "Teclea el tipo de datos deseado (e) entero, (f) fraccion, (c) char, (s) string: ";
                cin >> tipo;
                switch (tipo) {
                    case 'e':
                        cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                        cin >> cant;
                        creaListaEO(listaEO,cant); // Entero
                        listaE = listaEO;
                        break;
                    case 'f':
                        cant = 6;
                        creaListaFO(listaFO,cant); // Fracción
                        listaF = listaFO;
                        break;
                    case 'c':
                        cant = 20;
                        creaListaCO(listaCO,cant); // Character
                        listaC = listaCO;
                        break;
                    case 's':
                        cant = 6;
                        creaListaSO(listaSO,cant); // String
                        listaS = listaSO;
                        break;
                    default:
                        cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                        cin >> cant;
                        creaListaEO(listaEO,cant);
                        listaE = listaEO;
                        break;
                }
                break;
                
                
                // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            case 'b':
                cout << "Ordenamiento por Intercambio" << endl;
                switch (tipo) {
                    case 'e':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaE = intercambio(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaE);
                        break;
                    case 'f':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaF = intercambio(listaFO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaF);
                        break;
                    case 'c':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaC = intercambio(listaCO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaC);
                        break;
                    case 's':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaS = intercambio(listaSO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaS);
                        break;
                    default:
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaE = intercambio(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaE);
                        break;
                }
                break;
                
                
                // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            case 'c':
                cout << "Ordenamiento por burbuja" << endl;
                switch (tipo) {
                    case 'e':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaE = burbuja(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaE);
                        break;
                    case 'f':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaF = burbuja(listaFO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaF);
                        break;
                    case 'c':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaC = burbuja(listaCO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaC);
                        break;
                    case 's':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaS = burbuja(listaSO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaS);
                        break;
                    default:
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaE = burbuja(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaE);
                        break;
                }
                break;
                
                
                // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            case 'd': {
                cout << "Ordenamiento por Merge" << endl;
                switch (tipo) {
                    case 'e':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        //listaE = ordenaMerge(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaE);
                        break;
                    case 'f':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        //listaF = ordenaMerge(listaFO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaF);
                        break;
                    case 'c':
                        imprimir(listaCO);
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        //listaC = ordenaMerge(listaCO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaC);
                        break;
                    case 's':
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        //listaS = ordenaMerge(listaSO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaS);
                        break;
                    default:
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        //listaE = ordenaMerge(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Comparaciones: " << comparaciones << " Intercambios: " << intercambios << endl;
                        imprimir(listaE);
                        break;
                }
                break;
            }
                
                
                // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            case 'e': {
                cout << "Búsqueda Secuencial" << endl;
                switch (tipo) {
                    case 'e': {

                        int lostInt, posic = 0;
                        cout << "Teclea el entero que deseas buscar: ";
                        cin >> lostInt;
                        
                        // Tiempo incial
                        gettimeofday(&begin, 0);
                        try {
                            posic = busqSecuencial(listaE, comparaciones, lostInt);
                        } catch(runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        cout << "Posición del dato: " << posic <<  " Comparaciones: " << comparaciones << endl;
                        
                        break;
                    }
                    case 'f': {
                        
                        Fraccion f;
                        int numerador, denominador, posic = 0;
                        cout << "Teclea el numerador: ";
                        cin >> numerador;
                        f.setNumerador(numerador);
                        cout << "Teclea el denominador: ";
                        cin >> denominador;
                        f.setDenominador(denominador);
                        
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        try {
                            posic = busqSecuencial(listaFO, comparaciones, f);
                        } catch(runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        cout << "Posición del dato: " << posic <<  " Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    case 'c': {
                        // Caracter
                        int posic = 0;
                        char caracter;
                        
                        cout << "Teclea el caracter que deseas buscar: ";
                        cin >> caracter;
                        
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        try {
                            posic = busqSecuencial(listaCO, comparaciones, caracter);
                        } catch(runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        cout << "Posición del dato: " << posic <<  " Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    case 's': {
                        int posic = 0;
                        string palabra;
                        
                        cout << "Teclea la palabra que deseas buscar: ";
                        cin >> palabra;
                        
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        try {
                            posic = busqSecuencial(listaSO, comparaciones, palabra);
                        } catch(runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        cout << "Posición del dato: " << posic <<  " Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
                
                // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            case 'f': {
                int inferior, superior, enteroPerdido;
                
                cout << "Búsqueda Binaria" << endl;
                cout << "Teclea el límite inferior del vector: ";
                cin >> inferior;
                
                cout << "Teclea el límite superior del vector: ";
                cin >> superior;
                
                cout << "Teclea el número entero que deseas buscar: ";
                cin >> enteroPerdido;
                
                vector<int> listaOrdenada;
                creaListaOrdenada(listaOrdenada, inferior, superior);
                switch (tipo) {
                    case 'e': {
                        int posic = 0;
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        try {
                            posic = busqSecuencial(listaOrdenada, comparaciones, enteroPerdido);
                        } catch(runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        cout << "Posición del dato: " << posic <<  " Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    case 'f': {
                        cout << "Solo se puede con un vector de números" << endl;
                        break;
                    }
                    case 'c': {
                        cout << "Solo se puede con un vector de números" << endl;
                        break;
                    }
                    case 's': {
                        cout << "Solo se puede con un vector de números" << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case 'g': {
                switch (tipo) {
                    case 'e': {
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaE = intercambio(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        cout << "Ordenamiento por intercambio: ";
                        calculaTiempo(begin, end);
                        cout << endl;
                        
                        // ---------------
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaE = burbuja(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        cout << "Ordenamiento Burbuja: ";
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        cout<< endl;
                        
                        // ---------------
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        //listaE = ordenaMerge(listaEO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        cout << "Ordenamiento merge: ";
                        calculaTiempo(begin, end);
                        cout << endl;
                        
                        break;
                    }
                    case 'f': {
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaF = intercambio(listaFO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        // ---------------
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        listaF = burbuja(listaFO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        // ---------------
                        // Tiempo inicial
                        gettimeofday(&begin, 0);
                        
                        //listaF = ordenaMerge(listaFO, comparaciones, intercambios);
                        
                        // Tiempo final
                        gettimeofday(&end, 0);
                        calculaTiempo(begin, end);
                        
                        break;
                    }
                    case 'c': {
                        break;
                    }
                    case 's': {
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case 'z': {
                cout << endl << "Gracias" << endl;
                break;
            }
        }
    }    
    return 0;
}

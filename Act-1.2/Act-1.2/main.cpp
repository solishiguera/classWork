//
//  main.cpp
//  Act-1.2
//
//  Created by Diego Solis on 9/5/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>

#include "Fraccion.h"

//Intercambio —> O(n^2)
//Selección —> O(n^2)
//Burbuja —> O(n^2)
//Inserción —> O(n^2)
//Merge —> O(n log n)
//Quick —> O(n^2)
//Secuencial —> O(n)
//Binaria —> O(log23n)

template<class T>
vector<T> ordenaIntercambio(vector<T> &lista, int &comparaciones, int &intercambios) {
    intercambios = 0;
    comparaciones = 0;
    
    for (int i = 0; i < lista.size(); i++) {
        for (int j = 0; j < lista.size(); j++) {
            if (lista[i] < lista[j]) {
                swap(lista[j], lista[i]);
                intercambios++;
            }
            comparaciones++;
        }
    }
    return lista;
}


template<class T>
vector<T> ordenaSeleccion(vector<T> &lista, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    int menor;
    
    for (int i = 0; i < lista.size(); i++) {
        menor = i;
        for (int j = i + 1; j < lista.size(); j++) {
            comparaciones++;
            if (lista[j] < lista[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            intercambios++;
            swap(lista[i], lista[menor]);
        }
        
    }
    return lista;
}


template<class T>
vector<T> ordenaBurbuja(vector<T> &lista, int &comparaciones, int &intercambios) {
    intercambios = 0;
    comparaciones = 0;
    
    for (int i = 0; i < lista.size() - 1; i++) {
        for (int j = 0; j < lista.size() - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(lista[j + 1], lista[j]);
            }
        }
    }
    return lista;
}

template<class T>
vector<T> ordenaInsercion(vector<T> &lista, int &comparaciones, int &intercambios) {
    intercambios = 0;
    comparaciones = 0;
    int posicion = 0;
    
    for (int i = 0; i < lista.size(); i++) {
        posicion = i;
        while (lista[posicion] < lista[posicion - 1] && posicion != 0) {
            comparaciones++;
            intercambios++;
            swap(lista[posicion], lista[posicion-1]);
            posicion--;
        }
    }
    return lista;
}

template <class T>
void merge(vector<T> &lista, int inicio, int medio, int fin, int &comparaciones) {
    int i, j, pos;
    int f1 = medio - inicio + 1;
    int f2 = fin - medio;

    T arregloIzquierda[f1], arregloDerecha[f2];

    for (i = 0; i < f1; i++)
        arregloIzquierda[i] = lista[inicio + i];
    for (j = 0; j < f2; j++)
        arregloDerecha[j] = lista[medio + 1 + j];

    i = 0;
    j = 0;
    pos = inicio;
    
    while (i < f1 && j < f2) {
        comparaciones++;
        if (arregloIzquierda[i] <= arregloDerecha[j]) {
            lista[pos] = arregloIzquierda[i];
            i++;
        }
        else {
            lista[pos] = arregloDerecha[j];
            j++;
        }
        pos++;
    }

    while (i < f1) {
        lista[pos] = arregloIzquierda[i];
        i++;
        pos++;
    }

    while (j < f2) {
        lista[pos] = arregloDerecha[j];
        j++;
        pos++;
    }
}


template <class T>
void ordenaMerge(vector<T> &lista, int inicio, int fin, int &comparaciones) {
    comparaciones++;
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        ordenaMerge(lista, inicio, medio, comparaciones);
        ordenaMerge(lista, medio + 1, fin, comparaciones);
        
        merge(lista,inicio,medio,fin, comparaciones);
    }
}


template<class T>
int particion(vector<T> &lista, int menor, int mayor, int &comparaciones, int &intercambios) {
    T datoMayor = lista[mayor];
    int i = (menor - 1);
    
    for(int j = menor; j <= mayor - 1; j++) {
        comparaciones++;
        if (lista[j] <= datoMayor) {
            i++;
            intercambios++;
            swap(lista[i], lista[j]);
        }
    }
    intercambios++;
    swap(lista[i + 1], lista[mayor]);
    return (i + 1);
}


template<class T>
void quickSort(vector<T> &lista, int menor, int mayor, int &comparaciones, int &intercambios) {
    
    comparaciones++;
    if (menor < mayor) {
        int indiceParticion = particion(lista, menor, mayor, comparaciones, intercambios);
        
        quickSort(lista, menor, indiceParticion - 1, comparaciones, intercambios);
        quickSort(lista, indiceParticion + 1, mayor, comparaciones, intercambios);
    }
}

template<class T>
void busqSecuencial(vector<T> lista, int &comparaciones, T datoPerdido) {
    bool seEcontroDato = false;
    for (int i = 0; i < lista.size(); i++) {
        if(lista[i] == datoPerdido) {
            comparaciones++;
            cout << endl << "El dato se encuentra en la posición " << i << endl;
            seEcontroDato = true;
            break;
        }
        comparaciones++;
    }
    if (!seEcontroDato) {
        throw runtime_error("No se encontró el dato buscado");
    }
}

template <class T>
void busqBinaria(vector<T> lista, int &comparaciones, T datoPerdido) {
    comparaciones = 0;
    bool seEncontroDato = false;
    
    int centro, inferior, superior, valorCentral, sizeLista;
    inferior = 0;
    sizeLista = (int) lista.size();
    superior = sizeLista - 1;
    
    while (inferior <= superior) {
        centro = (inferior + superior) / 2;
        valorCentral = lista[centro];
        if (datoPerdido == valorCentral) {
            cout << endl << "El dato se encuentra en la posición " << centro << endl;
            break;
        } else if(datoPerdido < valorCentral) {
            superior = centro - 1;
        } else {
            inferior = centro + 1;
        }
    }
    
    if (!seEncontroDato) {
        throw runtime_error("No se encontró el dato buscado");
    }
    
}

/* ~~~~~~~~~~~~~~~ INCIO -> Funciones para crear VECTORES ~~~~~~~~~~~~~~~ */

// VECTOR ORDENADO
vector<int> creaVectorOrdenado(int inicio, int cantidadEnteros) {
    vector<int> vectorNumeros;
    for (int i = inicio; i <= cantidadEnteros; i++) {
        vectorNumeros.push_back(i);
    }
    return vectorNumeros;
}

// VECTOR DE ENTEROS
vector<int> creaVectorRandomEntero(int cantElementos, vector<int> &lista) {
    lista.clear();
    int valorRandom = 0;
    
    for (int i = 0; i < cantElementos; i++) {
        valorRandom = rand() %  9;
        lista.push_back(valorRandom);
    }
    return lista;
}

// VECTOR DE PALABRAS
vector<string> creaVectorRandomString(int cantElementos, vector<string> lista) {
    string palabraRandom;
    lista.clear();
    for (int i = 0; i < cantElementos; i++) {
        palabraRandom.clear();
        for (int i = 0; i < rand() % 6 + 4; i++) {
            palabraRandom += 'a' + rand() % 26;
        }
        lista.push_back(palabraRandom);
    }
    return lista;
}

// VECTOR DE CARACTERES
vector<char> creaVectorRandomCaracteres(int cantElementos, vector<char> lista) {
    lista.clear();
    for (int i = 0; i < cantElementos; i++) {
        lista.push_back('a' + rand() % 26);
    }
    return lista;
}

// VECTOR DE FRACCIONES
vector<Fraccion> creaVectorRandomFraccion(int cantElementos, vector<Fraccion> lista) {
    lista.clear();
    int numerador, denominador;
    
    for (int i = 0; i < cantElementos; i++) {
        numerador = rand() % 8 + 1;
        denominador = rand() %  8 + 1;
        lista.push_back(Fraccion(numerador, denominador));
    }
    return lista;
}

/* ~~~~~~~~~~~~~~~ FIN -> Funciones para crear VECTORES ~~~~~~~~~~~~~~~ */

// CALCULAR EL TIEMPO
void calculaTiempo(struct timeval begin, struct timeval end) {
    long seconds, microseconds;
    double elapsed;
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}

//IMPRIMIR LISTAS
template<class T>
void imprimeLista(vector<T> lista) {
    for (int i = 0; i < lista.size(); i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

int main() {
    /*
     vector<int> lista = {2,5,3,7,1,4};
     vector<char> lista = {'z','a','j','g','b','v'};
     vector<string> lista = {"Diego", "Marcela", "Fernando" "Alan", "Karla", "Solis"};
     vector<Fraccion> lista = {Fraccion(3, 4), Fraccion(5, 6), Fraccion(2, 5), Fraccion(7, 8), Fraccion(9, 2), Fraccion(1, 4)};
     */
    
    struct timeval begin, end;
    int comparaciones = 0;
    int intercambios = 0;
    vector<int> listaEntero;
    vector<char> listaCaracter;
    vector<string> listaString;
    vector<Fraccion> listaFraccion;
    
    char opcionUsuario = 'a';
    char opcionTipoDato = 'a';
    int cantElementos = 0;
    int rep = 0;
    
    do {
        cout << endl << "Ingresa la opción que desees: " << endl;
        cout << "a) Ordenamiento por intercambio" << endl;
        cout << "b) Ordenamiento por burbuja" << endl;
        cout << "c) Ordenamiento por seleccion" << endl;
        cout << "d) Ordenamiento por insercion" << endl;
        cout << "e) Ordenamiento por merge" << endl;
        cout << "f) Ordenamiento por quick sort" << endl;
        cout << "g) búsqueda secuencial o búsqueda binaria" << endl;
        cout << "h) salir" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Teclea opción: ";
        cin >> opcionUsuario;
        rep++; // Veces que se ejecuta programa
        if (opcionUsuario != 'g' && rep <= 1) {
            cout << "Ingresa la opción que deseas para tipo de dato: " << endl;
            cout << "a) Caracter" << endl;
            cout << "b) Entero" << endl;
            cout << "c) String" << endl;
            cout << "d) Fraccion" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Teclea opción: ";
            cin >> opcionTipoDato;
            cout << endl << "Cuantos datos?: ";
            cin >> cantElementos;
        }
        
        switch (opcionUsuario) {
            case 'a': { // INTERCAMBIO
                switch (opcionTipoDato) {
                        /* INCIO -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                    case 'a': { // CARACTER
                        vector<char> lista = creaVectorRandomCaracteres(cantElementos, listaCaracter);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaIntercambio(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'b': { // ENTERO
                        vector<int> lista = creaVectorRandomEntero(cantElementos, listaEntero);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaIntercambio(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'c': { // STRING
                        vector<string> lista = creaVectorRandomString(cantElementos, listaString);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaIntercambio(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'd': { // FRACCION
                        vector<Fraccion> lista = creaVectorRandomFraccion(cantElementos, listaFraccion);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaIntercambio(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break; 
                    }
                    default: {
                        break;
                    }
                        /* FIN -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                }
                //imprimeLista(lista);
                break;
            }
            case 'b': { // BURBUJA
                switch (opcionTipoDato) {
                        /* INCIO -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                    case 'a': { // CARACTER
                        vector<char> lista = creaVectorRandomCaracteres(cantElementos, listaCaracter);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaBurbuja(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'b': { // ENTERO
                        vector<int> lista = creaVectorRandomEntero(cantElementos, listaEntero);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaBurbuja(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'c': { // STRING
                        vector<string> lista = creaVectorRandomString(cantElementos, listaString);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaBurbuja(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'd': { // FRACCION
                        vector<Fraccion> lista = creaVectorRandomFraccion(cantElementos, listaFraccion);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaBurbuja(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                        /* FIN -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                }
                break;
            }
            case 'c': { // SELECCION
                switch (opcionTipoDato) {
                        /* INCIO -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                    case 'a': { // CARACTER
                        vector<char> lista = creaVectorRandomCaracteres(cantElementos, listaCaracter);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaSeleccion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'b': { // ENTERO
                        vector<int> lista = creaVectorRandomEntero(cantElementos, listaEntero);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaSeleccion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'c': { // STRING
                        vector<string> lista = creaVectorRandomString(cantElementos, listaString);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaSeleccion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'd': { // FRACCION
                        vector<Fraccion> lista = creaVectorRandomFraccion(cantElementos, listaFraccion);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaSeleccion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                        /* FIN -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                }
                break;
            }
            case 'd': { // INSERCION
                switch (opcionTipoDato) {
                        /* INCIO -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                    case 'a': { // CARACTER
                        vector<char> lista = creaVectorRandomCaracteres(cantElementos, listaCaracter);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaInsercion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'b': { // ENTERO
                        vector<int> lista = creaVectorRandomEntero(cantElementos, listaEntero);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaInsercion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'c': { // STRING
                        vector<string> lista = creaVectorRandomString(cantElementos, listaString);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaInsercion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'd': { // FRACCION
                        vector<Fraccion> lista = creaVectorRandomFraccion(cantElementos, listaFraccion);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        ordenaInsercion(lista, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                        /* FIN -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                }
                break;
            }
            case 'e': { // MERGE
                switch (opcionTipoDato) {
                        /* INCIO -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                    case 'a': { // CARACTER
                        vector<char> lista = creaVectorRandomCaracteres(cantElementos, listaCaracter);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        comparaciones = 0;
                        ordenaMerge(lista, 0, (int) lista.size() - 1, comparaciones);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    case 'b': { // ENTERO
                        vector<int> lista = creaVectorRandomEntero(cantElementos, listaEntero);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        comparaciones = 0;
                        ordenaMerge(lista, 0, (int) lista.size() - 1, comparaciones);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    case 'c': { // STRING
                        vector<string> lista = creaVectorRandomString(cantElementos, listaString);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        comparaciones = 0;
                        ordenaMerge(lista, 0, (int) lista.size() - 1, comparaciones);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    case 'd': { // FRACCION
                        vector<Fraccion> lista = creaVectorRandomFraccion(cantElementos, listaFraccion);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        comparaciones = 0;
                        ordenaMerge(lista, 0, (int) lista.size() - 1, comparaciones);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                        /* FIN -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                }
                break;
            }
            case 'f': { // QUICKSORT
                switch (opcionTipoDato) {
                        /* INCIO -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                    case 'a': { // CARACTER
                        vector<char> lista = creaVectorRandomCaracteres(cantElementos, listaCaracter);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        intercambios = 0;
                        comparaciones = 0;
                        quickSort(lista, 0, (int) lista.size() - 1, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'b': { // ENTERO
                        vector<int> lista = creaVectorRandomEntero(cantElementos, listaEntero);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        intercambios = 0;
                        comparaciones = 0;
                        quickSort(lista, 0, (int) lista.size() - 1, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'c': { // STRING
                        vector<string> lista = creaVectorRandomString(cantElementos, listaString);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        intercambios = 0;
                        comparaciones = 0;
                        quickSort(lista, 0, (int) lista.size() - 1, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    case 'd': { // FRACCION
                        vector<Fraccion> lista = creaVectorRandomFraccion(cantElementos, listaFraccion);
                        imprimeLista(lista);
                        gettimeofday(&begin, 0); // Inicio
                        intercambios = 0;
                        comparaciones = 0;
                        quickSort(lista, 0, (int) lista.size() - 1, comparaciones, intercambios);
                        gettimeofday(&end, 0); // Fin
                        imprimeLista(lista);
                        calculaTiempo(begin, end);
                        cout << "Comparaciones: " << comparaciones << ", Intercambios: " << intercambios << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                        /* FIN -> LLAMAR FUNCIÓN POR TIPO DE DATO */
                }
                break;
            }
                
            case 'g': {// Opción de búsqueda secuencial o binaria
                int cantNumeros, inicio;
                char opcionDosUsuario = 'm';
                vector<int> vectorNumeros;
                
                while (opcionDosUsuario != 'c') {
                    cout << "a) Búsqueda secuencial" << endl;
                    cout << "b) Búsqueda binaria" << endl;
                    cout << "c) salir" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Teclea opción: ";
                    cin >> opcionDosUsuario;
                    if (opcionDosUsuario == 'c')
                        break;
                    cout << "Teclea la cantidad de enteros que desees: ";
                    cin >> cantNumeros;
                    cout << "Teclea los límites de el vector de enteros" << endl;
                    cout << "Incio: ";
                    cin >> inicio;
                    
                    switch (opcionDosUsuario) {
                        case 'a':
                            vectorNumeros =  creaVectorOrdenado(inicio, cantNumeros);
                            int dato;
                            cout << "Qué dato buscas?: ";
                            cin >> dato;
                            
                            gettimeofday(&begin, 0); // Inicio
                            try {
                                busqSecuencial(vectorNumeros, comparaciones, dato);
                            } catch(runtime_error& e) {
                                cout << e.what() << endl;
                            }
                            gettimeofday(&end, 0); // Fin
                            calculaTiempo(begin, end);
                            cout << "Comparaciones: " << comparaciones << endl << endl;
                            
                            break;
                        case 'b': {
                            vectorNumeros =  creaVectorOrdenado(inicio, cantNumeros);
                            int dato;
                            cout << "Qué dato buscas?: ";
                            cin >> dato;
                            
                            gettimeofday(&begin, 0); // Inicio
                            try {
                                busqBinaria(vectorNumeros, comparaciones, dato);
                            } catch(runtime_error& e) {
                                cout << e.what() << endl;
                            }
                            gettimeofday(&end, 0); // Fin
                            calculaTiempo(begin, end);
                            cout << "Comparaciones: " << comparaciones << endl << endl;
                            
                            break;
                        }
                        default: { // Default menú secuencial y binario
                            break;
                        }
                    }
                }
                
                break; // Break de caso 'g'
            }
                
            default: { // Default de menú inicial
                break;
            }
                
        }
        
    } while (opcionUsuario != 'h');
    
    return 0;
}

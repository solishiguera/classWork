//
//  main.cpp
//  Act-1.1-Recursividad
//
//  Created by Diego Solis on 8/13/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sumaIterativa(int n, int &pasos)
{
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
        pasos++;
    }
    return suma;
}

int sumaRecursiva(int n, int &pasos)
{
    if (n > 1) {
        pasos++;
        return n + sumaRecursiva(n-1, pasos);
    } else {
        pasos++;
        return 1;
    }
}

int sumaDirecta(int n, int &pasos)
{
    pasos++;
    return (n * (n + 1)) / 2;
}

int factorial(int n, int & pasos)
{
    if (n <= 1) {
        pasos++;
        return 1;
    } else {
        pasos++;
        return n * factorial(n - 1, pasos);
    }
}

void patronCaracteres(int n, int m, char c)
{
    string caracteres = " ";
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            caracteres.push_back(' ');
            caracteres.push_back(c);
        }
        cout << caracteres << endl;
    } else {
        for (int i = 0; i < n; i++) {
            caracteres.push_back(' ');
        }
        
        for (int i = 0; i < m-(n-1); i++) {
            caracteres.push_back(c);
            caracteres.push_back(' ');
        }
        cout << caracteres << endl;
        patronCaracteres(n-1, m, c);
    }
}


// CUATRO EJERCICIOS DE HOJA
int fibonnaciRecursivo(int n)
{
    if (n <= 2) {
        return 1;
    } else {
        return fibonnaciRecursivo(n - 1) + fibonnaciRecursivo(n - 2);
    }
}

// Duda con la parte de truncar
double bacteriaRecursiva(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return bacteriaRecursiva((n-1)) * (3.78 - 2.34);
    }
}

// Comprobar
double inversionRecursiva(int cant, int mes)
{
    if (mes == 1)
    {
        return cant * 1.1875;
    } else {
        return inversionRecursiva(cant, mes - 1) * 1.1875;
    }
}

int potenciaRecursiva(int x, int y)
{
    if (y == 1) {
        return x;
    } else {
        return potenciaRecursiva(x, y - 1) * x;
    }
}



int main()
{
    int n;
    int pasos = 0;
    int o;
    char a;
    cout << endl << "~~~~~~~~~~~~~~~~~~~ Ejercicios Actividad 1.1 ~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "Ingrese un caracter: ";
    cin >> a;
    cout << "Teclee un número entero: ";
    cin >> n;
    o = n;
    cout << "Suma iterativa: " << sumaIterativa(n, pasos) << " --> Número de pasos: " << pasos << endl;
    pasos = 0;
    cout << "Suma recursiva: " << sumaRecursiva(n, pasos) << " --> Número de pasos: " << pasos << endl;
    pasos = 0;
    cout << "Suma directa: \t" << sumaDirecta(n, pasos) << " --> Número de pasos: " << pasos << endl;
    cout << "El factorial de " << n << " es: " << factorial(n, pasos) << " --> Número de pasos: " << pasos << endl;
    cout << endl << "Pirámide de caracteres: " << endl;
    patronCaracteres(n,o, a);
    
    
// CUATRO EJERCICIOS DE HOJA
    int monto, meses, x, y, m;
    
    cout << endl << "~~~~~~~~~~~~~~~~~~~ Ejercicios PDF Act 1.1 ~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "Ingrese un número: ";
    cin >> m;
    cout << "Secuencia Fibonnaci hasta " << m << ": " << fibonnaciRecursivo(m) << endl;
    cout << "Recursividad bacteria para " << m << " días: " << trunc(bacteriaRecursiva(m)) << endl;
    cout << "Ingresa el monto para calcular el interés: ";
    cin >> monto;
    cout << "Ingresa la cantidad de meses: ";
    cin >> meses;
    cout << "El monto final a pagarse es de: " << inversionRecursiva(monto, meses) << endl;
    cout << "Ingresa el valor de x: ";
    cin >> x;
    cout << "Ingresa el valor de y (potencia): ";
    cin >> y;
    cout << x <<" elevada a la potencia " << y << " es igual a: " << potenciaRecursiva(x, y) << endl << endl;
    return 0;
}

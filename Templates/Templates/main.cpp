//
//  main.cpp
//  Templates
//
//  Created by Diego Solis on 8/10/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#include "Fraccion.h"
#include "Oper.h"

template<class T>
T suma(T a, T b) {
    return a + b;
}

int sumaInt(int a, int b) {
    return a + b;
}

double sumaDouble(double a, double b) {
    return a + b;
}

float sumaFloat(float a, float b) {
    return a + b;
}

Fraccion sumaFraccion(Fraccion a, Fraccion b) {
    return a + b;
}

int main() {

/*
    int a = 10;
    int b = 20;
    double x = 10.5;
    double y = 20.5;
    float m = 20.54;
    float n = 30.46;
    Fraccion f = Fraccion(1,2);
    Fraccion g = Fraccion(1,4);
    string s = "Emilia";
    string t = "Moni";
    char h = '#';
    char i = '#';
    cout << "La suma de a + b es igual a " << suma(a,b) << endl;
    cout << "La suma de x + y es igual a " << suma(x,y) << endl;
    cout << "La suma de m + n es igual a " << suma(m,n) << endl;
    cout << "La suma de f + g es igual a " << suma(f,g) << endl;
    cout << "La suma de s + t es igual a " << suma(s,t) << endl;
    cout << "La suma de h + i es igual a " << suma(h,i) << endl;
*/
    int a = 0;
    int b = 1;
    Oper<int> operInt(a,b);
    try {
        cout << "La suma de a + b es igual a " << operInt.suma() << endl;
    } catch(runtime_error& e) {
        cout << e.what() << endl;
    }
    
    double c = 10.5;
    double d = 20.5;
    Oper<double> operDouble(c,d);
    cout << "La suma de c + d es igual a " << operDouble.suma() << endl;
    /*
    Fraccion f = Fraccion(1,2);
    Fraccion g = Fraccion(1,4);
    Oper<Fraccion> operFraccion(f,g);
    cout << "La suma de f + g es igual a " << operFraccion.suma() << endl;
    */
    
    
    return 0;
}

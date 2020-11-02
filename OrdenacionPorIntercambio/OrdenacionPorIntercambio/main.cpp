//
//  main.cpp
//  OrdenacionPorIntercambio
//
//  Created by Diego Solis on 8/17/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>


template<class T>
vector<T> intercambio(vector<T> lista)
{
    for(int i = 0; i < lista.size(); i++)
    {
        for(int j = 0; j < lista.size(); j++)
        {
            if(lista[i+1] < lista[i])
            {
                swap(lista[j], lista[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> lista;
    
}

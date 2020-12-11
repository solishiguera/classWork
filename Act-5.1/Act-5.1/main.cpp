//
//  main.cpp
//  Act-5.1
//
//  Created by Diego Solis on 12/6/20.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#include "HashC.h"
#include "HashQ.h"

int hashing(string str) {
    int len = (int) str.length();
    int key = 0; // La inicialicé, puede causar errores
    if (len == 1) {
        key = int(str[0]);
    } else {
        if (len == 2) {
            key = int(str[0]) + int(str[1]);
        } else {
            if (len >= 3) {
                key = int(str[1]) + int(str[2]);
            }
        }
    }
    
    return key % 11;
}

int main() {
    vector<string> lista = {"aaaa", "bbbb", "acac", "abab", "dddd", "dada", "cdcd", "eeee", "dede", "ffff", "efef"};
    
    cout << endl << "Quadratic" << endl;
    HashQ hash(lista);
    hash.print();
    cout << endl << "Chain" << endl;
    HashC hashTwo(lista);
    hashTwo.print();
    
    return 0;
}

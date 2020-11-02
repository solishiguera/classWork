//
//  main.cpp
//  AG05-CaracterUnico
//
//  Created by Diego Solis on 8/27/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <string>

int main() {
    map<char, int> mapita;
    vector<char> listaCar = {'a', 'b', 'c', 'a', 'c'};
    vector<char> newVector;
    
    
    for (int i = 0; i < 5; i++) {
        mapita[listaCar[i]] += 1;
    }
    

    for (int i = 0; i < listaCar.size(); i++) {
        for (int j = 0; j < mapita[i]; i++) {
            newVector.push_back(mapita[i]);
        }
    }
    
    if (mapita['a'] == 2) {
        cout << "lol" << endl;
    } else {
        cout << "lame" << endl;
    }
    
    return 0;
}

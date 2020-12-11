//
//  HashC.h
//  Act-5.1
//
//  Created by Diego Solis on 12/6/20.
//

#ifndef HashC_h
#define HashC_h

class HashC {
private:
    vector< vector<string> > table;
    int size;
    int qty;
    bool isFull(); // Complejidad O(1)
    bool alreadyExist(vector<string> collisions, string str); // Complejidad O(n)
public:
    HashC(int size);
    HashC(vector<string> list);
    void addStr(string str); // Complejidad O(n)
    bool findStr(string str); // Complejidad O(n)
    void print(); // Complejidad O(n^2)
    int hashing(string str); // Complejidad O(1)
};

HashC::HashC(vector<string> list) {
    qty = 0;
    size = (int) list.size();
    vector< vector<string> > tempTable(size);
    table = tempTable;
    for(auto str : list) {
        addStr(str);
    }
    
}

HashC::HashC(int size) {
    this-> size = size;
    qty = 0;
    vector< vector<string> > tempTable(size);
    table = tempTable;
}

// Complejidad O(n)
bool HashC::findStr(string str) {
    int index = hashing(str);
    return alreadyExist(table[index], str);
}

// Complejidad O(1)
int HashC::hashing(string str) {
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
    
    return key % size;
}

// Complejidad O(n)
void HashC::addStr(string str) {
    if(!isFull()) {
        int index = hashing(str);
        if (!alreadyExist(table[index], str)) {
            table[index].push_back(str);
            qty++;
        }
    } else {
        throw out_of_range("La tabla ya está llena");
    }
}

// Complejidad O(1)
bool HashC::isFull() {
    return qty == size;
}

// Complejidad O(n^2)
void HashC::print() {
    cout << "Hash Table" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": ";
        for(auto str : table[i]) {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << endl;
}



// Complejidad O(n)
bool HashC::alreadyExist(vector<string> collisions, string str) {
    typename vector<string>::iterator it;
    it = find(collisions.begin(), collisions.end(), str);
    if (it != collisions.end()) {
        return true;
    } else {
        return false;
    }
}

#endif /* HashC_h */

//
//  HashQ.h
//  Act-5.1
//
//  Created by Diego Solis on 12/6/20.
//

#ifndef HashQ_h
#define HashQ_h

class HashQ {
private:
    vector<string> table;
    vector<int> status;
    int size;
    int qty;
    bool isFull();
    int quadProbe(int index, int cont);
public:
    HashQ(int size);
    HashQ(vector<string> list);
    void addStr(string str); // Complejidad O(n)
    int findStr(string str);
    void print();
    int hashing(string str);
};

HashQ::HashQ(vector<string> list) {
    qty = 0; 
    size = (int) list.size();
    vector<string> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size, 0);
    status = tempStatus;
    for(auto str : list) {
        addStr(str);
    }
    
}

HashQ::HashQ(int size) {
    this-> size = size;
    qty = 0;
    vector<string> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size, 0);
    status = tempStatus;
}

int HashQ::findStr(string str) {
    int cont = 1;
    int index = hashing(str);
    while (status[index] != 0 && cont < size) {
        if(status[index] == 1 && table[index] == str) {
            return index;
        }
        index = quadProbe(index, cont);
        cont++;
    }
    return -1;
}

int HashQ::hashing(string str) {
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
void HashQ::addStr(string str) {
    if(!isFull()) {
        int index = hashing(str);
        if (status[index] == 0 || status[index] == 2) {
            table[index] = str;
            status[index] = 1;
            qty++;
        } else {
            // Validar si ya existe
            int cont = 1;
            int newIndex = quadProbe(index, cont);
            while (status[newIndex] == 1) {
                if (str == table[newIndex]) {
                    throw runtime_error("El valor ya existe en la tabla");
                }
                cont++;
                newIndex = quadProbe(index, cont);
            }
            table[newIndex] = str;
            status[newIndex] = 1; // Ocupado
            qty++;
        }
    } else {
        throw out_of_range("La tabla ya está llena");
    }
}

int HashQ::quadProbe(int index, int cont) {
    int newIndex;
    if (index + int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)) < 0) {
        newIndex = size - fmod(size - int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)), size);
    } else {
        newIndex = fmod(index + int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)), size);
    }
    return newIndex;
}

bool HashQ::isFull() {
    return qty == size;
}

void HashQ::print() {
    cout << "Hash Table" << endl;
    for(auto str : table) {
        cout << str << endl; 
    }
}


#endif /* HashQ_h */

//
//  HashQ.h
//  Hashing
//
//  Created by Diego Solis on 11/30/20.
//

#ifndef HashQ_h
#define HashQ_h

class HashQ {
private:
    vector<string> table; // No tiene caso usar templates porque siempre uso strings
    int size;
    int qty; // Cantidad de elementos que tengo en la tabla
    vector<int> status; // 0 -> vacío, 1 -> ocupado, 2 -> borrado; 3 edos
    int hashing(string data); //, int &key, int size); // me da índice de tabla
    int quadTest(int index); // manejo de colsiones
    int findData(string data); // Si lo encontró o no lo encontró
    bool isFull();
public:
    HashQ(vector<string> list);
    void addData(string data);
    bool deleteData(string data);
};

HashQ::HashQ(vector<string> list) {
    size = (int) list.size();
    qty = 0;
    vector<string> tmpTable(size);
    table = tmpTable; // Iniciar tabla vacía
    
    vector<int> tmpStatus(size, 0);
    status = tmpStatus; // Iniciar status en 0, vacío
    
    int index;
    for(auto data : list) {
        index = hashing(data);
        
    }
}

void HashQ::addData(string data) {
    if(!isFull()) {
        int index = hashing(data); // El index va ser de acuerdo a la llave (Hashing)
        int newIndex = quadTest(index); // Manejo de colisiones, (prueba cuadrática)
        table[newIndex] = data; // Guarda dato en casilla de nuevo index
        status[newIndex] = 1; // Poner que ya está llena casilla
        qty++;
    }
}

int HashQ::quadTest(int index) {
    if (status[index] != 1) { // Si está vacía o borrada, regreso index
        return index;
    }
    
    int cont = 1;
    int newIndex = index;
    while (status[newIndex] == 1) { // Mientras que no sea borrado y vacío
        newIndex = index + pow(-1, cont - 1) * pow((cont + 1)/ 2, 2); // Revisar si el elemento ya existe <----------- <-----------
        newIndex %= size;
        cont++;
    }
    
    return newIndex;
}

int HashQ::hashing(string data) { //, int &key, int size) {
    // key = (unsigned char) data[0]; // Regresa ascii extendido
    // key = int(data[0]); // Regresa el código ascii
    int key = 0;
    // Función hashing
    for (auto c : data) { // Sumar el valor ascii de todas las letras de palabra
        key += (unsigned char) c;
    }
    
    return key % size; // Size es 53, número primo más cercano a 50
}

bool HashQ::isFull() {
    return size == qty;
}


#endif /* HashQ_h */

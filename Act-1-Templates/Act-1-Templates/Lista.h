//
//  Lista.h
//  Act-1-Templates
//
//  Created by Diego Solis on 8/10/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Lista_h
#define Lista_h

template<class T>
class Lista {
public:
    Lista();
    void insert(T dato);
    T erase();
    T getData(int posic);
    int getSize();
    void print();
    
private:
    T data[100];
    // int max;
    int size;
};

template<class T>
Lista<T>::Lista() {
    size = 0;
}

template<class T>
void Lista<T>::insert(T dato) {
    if(size < 100) {
        data[size++] = dato;
    } else {
        throw runtime_error("La lista está llena");
    }
}

template<class T>
T Lista<T>::erase() {
    if (size > 0) {
        size--;
        return data[size];
    } else {
        throw runtime_error("No hay elementos");
    }
}

template<class T>
T Lista<T>::getData(int posic) {
    if(posic >= 0 && posic < size && size != 0) {
        return data[posic];
    } else {
        throw runtime_error("Posición inválida");
    }
}

template<class T>
int Lista<T>::getSize() {
    return size;
}

template<class T>
void Lista<T>::print() {
    if (size > 0 && size < 100) {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]" << " - " << data[i] << endl;
        }
    } else {
        cout << "La lista está vacía" << endl;
    }
}



#endif /* Lista_h */

//
//  HashQ.h
//  Hashing
//
//  Created by Diego Solis on 11/30/20.
//

#ifndef HashQ_h
#define HashQ_h

template<class T>
class HashQ {
private:
    vector<T> table;
    int size;
    vector<int> status; // 0 -> vacío, 1 -> ocupado, 2 -> borrado; 3 edos
    int hashing(T data); // me da índice de tabla
    int quadTest(int index); // manejo de colsiones
    int findData(T data); // Si lo encontró o no lo encontró
public:
    HashQ(vector<T> list);
};



#endif /* HashQ_h */

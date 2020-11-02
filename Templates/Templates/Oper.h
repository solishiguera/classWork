//
//  Oper.h
//  Templates
//
//  Created by Diego Solis on 8/10/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Oper_h
#define Oper_h

template<class T>
class Oper {
private:
    T a;
    T b;
public:
    //Oper();
    Oper(T a, T b);
    T suma();
};
/*
Oper::Oper() {
    a = 0;
    b = 0;
}
*/
template<class T>
Oper<T>::Oper(T a, T b) {
    this->a = a;
    this->b = b;
}

template<class T>
T Oper<T>::suma() {
    if (a+b != 1) {
        return a + b;
    } else {
        throw runtime_error("Error creado para el ejemplo");
    }
    
}

#endif

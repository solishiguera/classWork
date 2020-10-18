//
//  Stack.h
//  Stack
//
//  Created by Diego Solis on 10/17/20.
//

#ifndef Queue_h
#define Queue_h
#include "Node.h"

template<class T>
struct Stack {
    Node<T>* head;
    Node<T>* tail;
    int size = 0;
    T pop(); // use exceptions
    void push(T data);
    T top(); // use exceptions
    int getSize();
    void clear();
    void printElements();
    bool isEmpty();
    void operator=(initializer_list<T> list);
};

template<class T>
bool Stack<T>::isEmpty() {
    return size == 0;
}

// Complejidad O(1)
template<class T>
T Stack<T>::pop() {
    if (!isEmpty()) {
        T data = head -> data;
        Node<T>* aux = head;
        head = aux-> next;
        delete aux;
        size--;
        return data;
    }
    throw out_of_range("La queue está vacía");
}

// Complejidad O(1)
template<class T>
void Stack<T>::push(T data) {
    if (isEmpty()) {
        head = new Node<T>(data);
        tail = head;
        size++;
    } else {
        Node<T>* aux = head;
        head = new Node<T>(data);
        head-> next = aux;
        size++;
    }
}

// Complejidad O(1)
template<class T>
T Stack<T>::top() {
    if(!isEmpty()) {
        return head-> data;
    }
    throw out_of_range("El stack está vacío");
}

// Complejidad O(1)
template<class T>
int Stack<T>::getSize() {
    return size;
}

// Complejidad O(n)
template<class T>
void Stack<T>::clear() {
    Node<T>* aux = head;
    Node<T>* auxDos = head;
    while(aux != NULL) {
        auxDos = aux->next;
        delete aux;
        aux = auxDos;
        size--;
    }
}

// Complejidad O(n)
template<class T>
void Stack<T>::operator=(initializer_list<T> list) {
    if(isEmpty()) {
        for(T i : list) {
            push(i);
        }
    } else {
        throw runtime_error("Error: la lista no está vacía");
    }
}

// Complejidad O(n)
template<class T>
void Stack<T>::printElements() {
    Node<T>* aux = head;
    for (int i = 0; i < size; i++) {
        cout << aux->data << endl;
        aux = aux->next;
    }
    cout << endl;
}
#endif /* Queue_h */

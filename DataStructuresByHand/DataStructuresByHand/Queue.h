//
//  Queue.h
//  dataStructures
//
//  Created by Diego Solis on 10/1/20.
//

#ifndef Queue_h
#define Queue_h
#include "Node.h"

template<class T>
struct Queue {
    Node<T>* head;
    int size = 0;
    void dequeue();
    void enqueue(T data);
    T front();
    T back();
    bool isEmpty();
    void printElements();
    int getSize();
    void clear();
    void operator=(initializer_list<T> Queue);
    T& operator[](int index);
};

template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

template<class T>
void Queue<T>::dequeue() {
    if (!isEmpty()) {
        Node<T>* aux = head;
        head = head-> next;
        delete aux;
        size--;
    } else {
        throw out_of_range("La queue está vacía");
    }
}

template<class T>
void Queue<T>::enqueue(T data) {
    if (!isEmpty()) {
        Node<T>* aux = head;
        while (aux->next != NULL) {
            aux = aux ->  next;
        }
        aux->next = new Node<T>(data);
    } else {
        head = new Node<T>(data);
    }
    size++;
}

template<class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    } else {
        throw out_of_range("El queue está vacío");
    }
}

template<class T>
T Queue<T>::back() {
    if (!isEmpty()) {
        Node<T>* aux = head;
        while (aux-> next != NULL) {
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw out_of_range("El queue está vacío");
    }
}

template<class T>
void Queue<T>::printElements() {
    Node<T>* aux = head;
    for (int i = 0; i < size; i++) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
void Queue<T>::clear() {
    for (int i = 1; i < size; i++) {
        dequeue();
    }
    size = 0;
}

template<class T>
void Queue<T>::operator=(initializer_list<T> list) {
    if(isEmpty()) {
        for(T i : list) {
            enqueue(i);
        }
    } else {
        throw runtime_error("Error: la lista no está vacía");
    }
}

template<class T>
T& Queue<T>::operator[](int index) {
    if (index >= 1 && index <= size) {
        Node<T>* aux = head;
        int i = 1;
        while (aux != NULL) {
            if (i == index) {
                return aux-> data;
            }
            aux = aux->next;
            i++;
        }
    }
    throw out_of_range("Posición inválida.");
}

#endif /* Queue_h */

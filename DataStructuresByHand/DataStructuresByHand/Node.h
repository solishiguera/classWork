//
//  Nodo.h
//  node
//
//  Created by Diego Solis on 9/21/20.
//

#pragma once


template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node(T data);
    Node(T data, Node<T>* next);
    /*
    T getData();
    void setData(T data);
    void setNext(Node<T>* next);
    Node<T>* getNextData();
    */
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T>* next) {
    this->data = data;
    this->next = next;
}

/*
template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<class T>
void Node<T>::setNext(Node<T>* next) {
    this-> next = next;
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
Node<T>* Node<T>::getNextData() {
    return next;
}
*/

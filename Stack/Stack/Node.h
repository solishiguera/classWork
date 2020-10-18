//
//  Node.h
//  Stack
//
//  Created by Diego Solis on 10/17/20.
//

#pragma once

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node(T data);
    Node(T data, Node<T>* next);
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


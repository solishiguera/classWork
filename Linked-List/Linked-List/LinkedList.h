//
//  LinkedList.h
//  Linked-List
//
//  Created by Diego Solis on 09/24/20.
//

#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"

template <class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
    bool isEmpty();
    void merge(int ini, int mid, int fin);
    void mergeSort(int inicio, int fin);
public:
    void addFirst(T data);
    void addLast(T data);
    bool deleteData(T data);
    void deleteAt(int index);
    T getData(int index); // Use exceptions
    void updateAt(int index, T newData); // Use exceptions
    void updateData(T data, T newData); // Use exceptions
    int findData(T data); // Use exceptions?
    void sort();
};

template <class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

template <class T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
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

template <class T>
bool LinkedList<T>::deleteData(T data) {
    if(!isEmpty()) {
        if (head-> data == data) {
            Node<T>* aux = head;
            head = aux-> next;
            delete aux;
            size--;
            return true;
        } else {
            if (head-> next != NULL) {
                Node<T>* aux = head-> next;
                Node<T>* prev = head;
                while (aux != NULL) {
                    if (aux-> data == data) {
                        prev-> next = aux-> next;
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux-> next;
                    }
                }
            }
        }
    }
    return false;
}

template <class T>
void LinkedList<T>::deleteAt(int index) {
    if(index >= 1 && index <= size) {
        Node<T>* aux = head-> next;
        Node<T>* prev = head;
        int i = 0;
        while(aux != NULL) {
            if(i == index) {
                prev = aux -> next;
                delete aux;
                size--;
                return;
            }
            prev = aux;
            aux = aux-> next;
            i++;
        }
    }
}

template <class T>
T LinkedList<T>::getData(int index) {
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

// NO SE SI YA ESTA COMPLETO
template <class T>
void LinkedList<T>::updateAt(int index, T newData) {
    if(index >= 1 && index <= size) {
        Node<T>* aux = head;
        int i = 0;
        while(aux != NULL) {
            if(i == index) {
                aux->data = newData;
                return;
            }
            aux = aux-> next;
            i++;
        }
    }
    
    throw out_of_range("Posición inválida");
}


// TERMINAR
template <class T>
void LinkedList<T>::updateData(T data, T newData) {
    
}

// TERMINAR
template <class T>
int LinkedList<T>::findData(T data) {
    int posI = 1;
    int posF = size;
    int posM = (posI + posF)  / 2;
    bool found = false;
    //sort();
    while(posI <= posF && !found) {
        if(data < getData(posM)) {
            posF = posM - 1;
        } else {
            if(data > getData(posM)) {
                posI = posM + 1;
            } else {
                if (data == getData(posM)) {
                    found = true;
                }
            }
        }
        posM = (posI + posF) / 2;
    }
    
    if(found) {
        return posM;
    } else {
        throw runtime_error("Posición inválida");
    }
}


// SORT BEGINS
template<class T>
void LinkedList<T>::merge(int ini, int mid, int fin) {
    Queue<T> listaL;
    Queue<T> listaR;
    int pos, f1, f2, i, j;
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;
    
    for(i = 0; i < f1; i++) {
        listaL.enqueue(getData(ini + i));
    }
    
    for(j = 0; j < f2; j++) {
        listaR.enqueue(getData(mid + 1 + j));
    }
    
    i = 0;
    j = 0;
    pos = ini;
    
    while(i < f1 && j < f2) {
        if((listaL.front()).key() <= (listaR.front()).key()) {
            updateAt(pos, listaL.dequeue());
            i++;
        } else {
            updateAt(pos, listaR.dequeue());
            j++;
        }
        pos++;
    }
    
    while(i < f1) {
        updateAt(pos, listaL.dequeue());
        i++;
        pos++;
    }
    
    while(j < f2) {
        updateAt(pos, listaR.dequeue());
        j++;
        pos++;
    }
}

template<class T>
void LinkedList<T>::mergeSort(int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergeSort(inicio, medio);
        mergeSort(medio + 1, fin);
        
        merge(inicio,medio,fin);
    }
}

template<class T>
void LinkedList<T>::sort() {
    mergeSort(1, size);
}
// SORT ENDS

#endif /* LinkedList_h */

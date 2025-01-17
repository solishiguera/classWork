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
    int size = 0;
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
    int findData(T data); // Use exceptions
    void sort();
    void printElements();
    void operator=(initializer_list<T> LinkedList);
    T& operator[](int index);
    void clear();
    void duplicate();
    void removeDuplicates();
    void reverse();
};

// Complejidad O(n)
template<class T>
void LinkedList<T>::operator=(initializer_list<T> list) {
    if(isEmpty()) {
        for(T i : list) {
            addLast(i);
        }
    } else {
        throw runtime_error("Error: la lista no está vacía");
    }
}

// Complejidad O(n)
template<class T>
T& LinkedList<T>::operator[](int index) {
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
    throw out_of_range("Posición inválida");
}

// Complejidad O(n)
template <class T>
void LinkedList<T>::printElements() {
    Node<T>* aux = head;
    for (int i = 0; i < size; i++) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Complejidad O(1)
template <class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

// Complejidad O(1)
template <class T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data, head);
    size++;
}

// Complejidad O(n)
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

// Complejidad O(n)
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

// Complejidad O(n)
template <class T>
void LinkedList<T>::deleteAt(int index) {
    if(index < 1 || index > size) {
        throw out_of_range("Posición no es válida");
    }
    
    Node<T>* aux = head;
    int cont = 2;
    
    if (index == 1) {
        head = aux-> next;
        delete aux;
        size --;
        return;
    }
    
    while (cont < index && aux-> next != NULL) {
        aux = aux-> next;
        cont++;
    }
    
    if(cont == index && aux-> next != NULL){
        Node<T>* newAux = aux-> next;
        aux-> next = newAux-> next;
        delete newAux;
        size--;
        return;
    }
}

// Complejidad O(n)
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

// Complejidad O(n)
template <class T>
void LinkedList<T>::updateAt(int index, T newData) {
    if (!isEmpty()) {
        Node<T>* aux = head;
        int cont = 1;
        while (cont != index && aux-> next != NULL) {
            aux = aux-> next;
            cont++;
        }
        aux->data = newData;
        return;
    }
    throw out_of_range("Position invalid");
}

// Complejidad O(n)
template <class T>
void LinkedList<T>::updateData(T data, T newData) {
    Node<T>* aux = head;
    while (aux-> data != data && aux->next != NULL) {
        aux = aux-> next;
    }
    
    if (aux-> data == data) {
        aux-> data = newData;
        return;
    } else {
        throw out_of_range("No se encontró el dato");
    }
}

// Complejidad O(log(n))
template <class T>
int LinkedList<T>::findData(T data) {
    int posI = 1;
    int posF = size;
    int posM = (posI + posF)  / 2;
    bool found = false;
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
// Complejidad O(log(n))
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
        if(listaL.front() <= listaR.front()) {
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

// Complejidad O(n)
template<class T>
void LinkedList<T>::clear() {
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
void LinkedList<T>::duplicate() {
    Node<T>* aux = head;
    Node<T>* siguiente = aux-> next;
    Node<T>* duplica;
    
    while (aux-> next != NULL) {
        siguiente = aux-> next;
        duplica = new Node<T>(aux->data);
        aux->next = duplica;
        duplica->next = siguiente;
        aux = siguiente;
        size++;
    }
    addLast(aux->data);
}

// Complejidad O(n^2)
template<class T>
void LinkedList<T>::removeDuplicates() {
    int cont = 2;
    while (cont <= size) {
        deleteAt(cont);
        cont ++;
    }
    
}

// Complejidad O(n^3)
template<class T>
void LinkedList<T>::reverse() {
    int cont = size;
    Node<T>* aux = head;
    T oldData;
    while (cont > size/2) {
        oldData = getData(cont);
        updateAt(cont, aux->data);
        aux-> data = oldData;
        aux = aux-> next;
        cont--;
    }
}

#endif /* LinkedList_h */

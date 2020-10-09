//
//  LinkedList.h
//  node
//
//  Created by Diego Solis on 9/24/20.
//

#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"
#include "Queue.h"

template <class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
    void mergeSort(int inicial, int fin);
    void merge(int inicial, int medio, int fin); // Revisar, marca error.
public:
    LinkedList();
    T& operator[](int index);
    void operator=(initializer_list<T> LinkedList);
    void addFirst(T data);
    void addLast(T data);
    void printElements();
    bool isEmpty();
    bool deleteData(T data);
    void deleteAt(int index); // FINISH
    T getData(int index);
    void updateAt(int position, T data); // FINISH
    void updateData(T data, T newData);
    int findData(T data);
    void insertAt(int index, T newData);
    // Actividad Final
    void clear(); // Es un for barriendo todos y limpiando cada elemento
    void sort();
    void duplicate(); // FINISH
    void removeDuplicates();
    void reverse(); // FINISH
};

// FIX IT DOES NOT WORK
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

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    size = 0;
}

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
void LinkedList<T>::printElements() {
    Node<T>* aux = head;
    for (int i = 0; i < size; i++) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
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

// FINISH -> PARECIDO AL DELETE AT
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

// FINISH -> PARECIDO AL DELETE DATA
template <class T>
void LinkedList<T>::updateData(T data, T newData) {
    
}

template<class T>
void LinkedList<T>::merge(int ini, int mid, int fin) {
    Queue<T> listaL;
    Queue<T> listaR;
    int pos, f1, f2, i, j;
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;
    
    for(i = 1; i < f1; i++) {
        //listaL.addLast(getData(ini + i - 1));
        listaL.enqueue(getData(ini + i -1));
    }
    
    for(j = 1; j < f2; j++) {
        //listaR.addLast(getData(mid + 1 + j - 1));
        listaR.enqueue(getData(mid + 1+j - 1));
    }
    
    i = 1;
    j = 1;
    
    while(i <= f1 && j <= f2) {
        if(listaL[i] <= listaR[j]) {
            updateAt(pos, listaL[i]);
            i++;
        } else {
            updateAt(pos, listaR[j]);
            j++;
        }
        pos++;
    }
    
    while(i <= f1) {
        updateAt(pos, listaL[i]);
        i++;
        pos++;
    }
    
    while(j <= f2) {
        updateAt(pos, listaR[j]);
        j++;
        pos++;
    }
    
}

template<class T>
void LinkedList<T>::mergeSort(int inicial, int fin) {
    if(inicial < fin) {
        int medio = (inicial + fin) / 2;
        mergeSort(inicial, medio);
        mergeSort(medio + 1, fin);
        merge(inicial, medio, fin);
    }
}

template<class T>
void LinkedList<T>::sort() {
    mergeSort(1, size);
}

template<class T> // NO FUNCIONA
void LinkedList<T>::insertAt(int index, T newData) {
    if(index >= 1 && index <= size) {
        if(index == 1) {
            head = new Node<T>(newData, head);
            size++;
            return;
        } else {
            Node<T>* aux = head->next;
            Node<T>* prev = head;
            int i = 2;
            while(aux != NULL) {
                if(i == index) {
                    prev->next = new Node<T>(newData, aux);
                    size++;
                    return;
                }
                aux = aux-> next;
                prev = aux;
                i++;
            }
        }
    }
    throw out_of_range("Posición inválida");
}

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

template<class T>
void LinkedList<T>::removeDuplicates() {
    Node<T>* aux = head;
    LinkedList<T> list = *this;
    clear();
    for (int i = 1; i < list.size(); i++) {
        if(!findData(aux->data)) {
            addLast(aux->data);
        }
    }
}

template <class T>
void LinkedList<T>::clear() { // Es un for barriendo todos y limpiando cada elemento
    for(int i = 1; i < size; i++) {
        Node<T>* aux = head;
        head = aux-> next;
        delete aux;
        i++;
    }
    size = 0;
}

#endif /* LinkedList_h */

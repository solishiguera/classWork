//
//  Queue.h
//  BinarySearchTrees
//
//  Created by Diego Solis on 10/25/20.
//

#ifndef Queue_h
#define Queue_h

template<class T>
struct Queue {
    Node<T>* head;
    Node<T>* tail;
    int size = 0;
    T dequeue();
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

// Complejidad O(n)
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
    throw out_of_range("Posición inválida");
}

// Complejidad O(1)
template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

// Complejidad O(1)
template<class T>
T Queue<T>::dequeue() {
    if (!isEmpty()) {
        T data = head -> data;
        Node<T>* aux = head;
        head = aux-> right;
        delete aux;
        size--;
        
        if(isEmpty()) {
            tail = NULL;
        }
        return data;
    }
        throw out_of_range("La queue está vacía");
}

// Complejidad O(1)
template<class T>
void Queue<T>::enqueue(T data) {
    if(!isEmpty()) {
        tail-> right = new Node<T>(data);
        tail = tail->right;
        size++;
        return;
    } else {
        head = new Node<T>(data);
        tail = head;
        size++;
        return;
    }
}

// Complejidad O(1)
template<class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    } else {
        throw out_of_range("El queue está vacío");
    }
}

// Complejidad O(1)
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

// Complejidad O(n)
template<class T>
void Queue<T>::printElements() {
    Node<T>* aux = head;
    for (int i = 0; i < size; i++) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Complejidad O(1)
template<class T>
int Queue<T>::getSize() {
    return size;
}

// Complejidad O(n)
template<class T>
void Queue<T>::clear() {
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
void Queue<T>::operator=(initializer_list<T> list) {
    if(isEmpty()) {
        for(T i : list) {
            enqueue(i);
        }
    } else {
        throw runtime_error("Error: la lista no está vacía");
    }
}

#endif /* Queue_h */

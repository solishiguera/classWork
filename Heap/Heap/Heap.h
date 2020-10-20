//
//  Heap.h
//  Heap
//
//  Created by Diego Solis on 10/19/20.
//

#pragma once

#include "DLL.h"

template<class T>
class Heap {
private:
    DoublyLinkedList<T> heap;
    int size;
    void downSort(int index);
    void upSort();
    void swap(int a, int b);
public:
    Heap();
    Heap(DoublyLinkedList<T> list);
    bool isEmpty();
    void print();
    T remove();
    void insertElement(T data);
};

template<class T>
void Heap<T>::insertElement(T data) {
    heap.addLast(data);
    size++;
    upSort();
}

template<class T>
void HeapSort(DoublyLinkedList<T>& list, string order = "ascending") {
    Heap<T> heapAux(list);
    list.clear();
    while (!heapAux.isEmpty()) {
        if(order == "ascending") {
            list.addFirst(heapAux.remove());
        } else {
            list.addLast(heapAux.remove());
        }
    }
}

template<class T>
T Heap<T>::remove() {
    if (!isEmpty()) {
        T aux = heap[1];
        swap(1, size); // índices
        heap.deleteLast();
        size --;
        downSort(1);
        return aux;
    } else {
        throw runtime_error("The heap is empty");
    }
}

template<class T>
Heap<T>::Heap() {
    size = 0;
}

template<class T>
void Heap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}
template<class T>
void Heap<T>::upSort() {
    int pos = size;
    while (pos > 1) {
        int father = pos / 2;
        if(heap[pos] > heap[father]) {
            swap(father, pos);
            pos = father;
        } else {
            pos = 1;
        }
    }
}

template<class T>
void Heap<T>::downSort(int index) {
    while (index >= 1) {
        int pos = index;
        while (pos * 2 <= size) {
            int s1 = pos * 2; // Si la lista empieza en 0, sería pos*2+1
            int s2 = pos * 2 + 1; // Si la lista empieza en 0, sería pos*2+2
            int max;
            if (s2 > size) {
                max = s1;
            } else {
                heap[s1] > heap[s2] ? max = s1 : max = s2;
            }
            if (heap[max] > heap[pos]) {
                swap(pos, max);
                pos = max;
            } else {
                pos = size;
            }
        }
        
        index--;
    }
}

template<class T>
Heap<T>::Heap(DoublyLinkedList<T> list) {
    if (!list.isEmpty()) {
        heap = list;
        size = heap.getSize();
        int index = size / 2;
        downSort(index);
    }
}

template<class T>
bool Heap<T>::isEmpty() {
    return size == 0;
}

template<class T>
void Heap<T>::print() {
    heap.print();
}

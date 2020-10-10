//
//  BST.h
//  dataStructures
//
//  Created by Diego Solis on 10/5/20.
//

#ifndef BST_h
#define BST_h
#include "Node.h"

template<class T>
class BST {
private:
    Node<T>* root;
    int howManyChilds(Node<T>* aux);
public:
    BST() {root = NULL;}
    void insert(T data);
    bool isEmpty();
    void printTree(Node<T>* aux, int level);
    void print();
    void removeElement(T data);
};

template<class T>
int BST<T>::howManyChilds(Node<T>* aux) {
    int cont = 0;
    aux->left == NULL ? cont++ : cont = cont;
    aux->right == NULL ? cont++ : cont = cont;
    
    return cont;
}

template<class T>
void BST<T>::insert(T data) {
    if (isEmpty()) {
        root = new Node<T>(data);
    } else {
        Node<T>* aux = root;
        while (aux != NULL) {
            if (data < aux->data) {
                if (aux->left == NULL) {
                    aux->left = new Node<T>(data);
                    return;
                } else {
                    aux = aux->left;
                }
            } else {
                if (aux->right == NULL) {
                    aux->right = new Node<T>(data);
                    return;
                } else {
                    aux = aux-> right;
                }
            }
        }
    }
}

template<class T>
void BST<T>::printTree(Node<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right, level+1);
        for (int i = 0; i << level; i++) {
            cout << "    ";
        }
        cout << aux->data << endl;
        printTree(aux->left, level+1);
    }
}

template<class T>
void BST<T>::print() {
    int level = 0;
    cout << endl;
    printTree(root, level);
    cout << endl;
    
}

template<class T>
bool BST<T>::isEmpty() {
    return root == NULL;
}

#endif /* BST_h */

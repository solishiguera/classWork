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
    void printTree(Node<T>* aux, int level);
    int size = 0;
public:
    BST() {root = NULL;}
    void insert(T data);
    bool isEmpty();
    void print();
    void removeElement(T data);
    bool find(T data);
    //void visit(int opcion);
};

template<class T>
bool BST<T>::find(T data) {
    Node<T>* aux = root;
    while (aux->data != data) {
        data >= aux->data ? aux = aux->right : aux = aux ->left;
    }
    
    if (aux-> data == data) {
        return true;
    }
    
    throw out_of_range("No se encontró el dato ingresado");
}

/*
 template<class T>
 void BST<T>::visit(int opcion) {
 switch (opcion) {
 case 1: {
 // Preorder
 break;
 }
 case 2: {
 break;
 }
 case 3: {
 break;
 }
 case 4: {
 break;
 }
 
 default:
 break;
 }
 }
 */

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
                    size++;
                    return;
                } else {
                    aux = aux->left;
                }
            } else {
                if (aux->right == NULL) {
                    aux->right = new Node<T>(data);
                    size++;
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
        for (int i = 0; i < level; i++) {
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
void BST<T>::removeElement(T data) {
    if (!isEmpty()) {
        Node<T>* father = root;
        Node<T>* aux = father;
        bool found = false;
        while (!found && aux != NULL) {
            if (data == aux-> data) {
                found = true;
            } else {
                father = aux;
                if (data < aux-> data) {
                    aux = aux-> left;
                } else {
                    aux = aux-> right;
                }
            }
        }
        
        if (found) {
            switch (howManyChilds(aux)) {
                case 0: {
                    if (aux == root) {
                        delete aux;
                        root = NULL;
                    } else {
                        data < father-> data ? father-> left = NULL : father-> right = NULL;
                        delete aux;
                    }
                }
                    
                    break;
                case 1: {
                    if(aux == root) {
                        root-> left != NULL ? root = root-> left : root = root-> right;
                    } else {
                        if (data < father-> data) {
                            aux-> left != NULL ? father-> left = aux-> left : father-> left = aux-> right;
                        } else {
                            aux -> left != NULL ? father-> right = aux-> left : father-> right = aux-> right;
                        }
                    }
                    delete aux;
                }
                    
                    break;
                case 2: {
                    Node<T>* father = aux;
                    Node<T>* max = aux-> left;
                    
                    if (max-> right == NULL) {
                        aux-> data = max-> data;
                        father-> left = max-> left;
                        delete max;
                    } else {
                        bool found = false;
                        while (!found) {
                            if (max-> right == NULL) {
                                found = true;
                            } else {
                                father = max;
                                max = max-> right;
                            }
                        }
                        aux-> data = max-> data;
                        father-> right = max-> left;
                        delete max;
                    }
                }
                    
                    break;
                default: {
                    break;
                }
            }
        }
        
    }

    /*
     bool isOnRight = false;
     
     if(root-> data == data) {
     root = NULL;
     }
     
     // Esto en teoría resuelve parte uno
     while (aux->data != data) {
     if (data < aux->data) {
     if (aux->left->data == data) {
     auxDos = aux;
     isOnRight = false;
     }
     aux = aux->left;
     } else {
     if (aux->right->data == data) {
     auxDos = aux;
     isOnRight = true;
     }
     aux = aux-> right;
     }
     }
     
     if (isOnRight) {
     auxDos->right = NULL;
     delete aux;
     return;
     } else {
     auxDos->left = NULL;
     delete aux;
     return;
     }
     throw runtime_error("No se encontró el dato buscado");
     */
}

template<class T>
bool BST<T>::isEmpty() {
    return root == NULL;
}

#endif /* BST_h */

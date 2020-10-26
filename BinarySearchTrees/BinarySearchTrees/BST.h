//
//  BST.h
//  dataStructures
//
//  Created by Diego Solis on 10/5/20.
//

#ifndef BST_h
#define BST_h

#include "Stack.h"

template<class T>
class BST {
private:
    Node<T>* root;
    int howManyChilds(Node<T>* aux);
    void printTree(Node<T>* aux, int level);
    void preOrder(Node<T>* aux);
    void inOrder(Node<T>* aux);
    void postOrder(Node<T>* aux);
    void levelByLevel();
    int size = 0;
public:
    BST() {root = NULL;}
    void insert(T data);
    bool isEmpty();
    void print();
    void removeElement(T data);
    bool find(T data);
    
    void visit(int order);
    void ancestors(T data);
    int whatLevelAmI(T data);
    int height(Node<T> *node);
    int heightBST();
    int childs(Node<T> *node);
};

// Complejidad O(n)
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

// Complejidad O(1)
template<class T>
int BST<T>::howManyChilds(Node<T>* aux) {
    int cont = 0;
    aux->left == NULL ? cont++ : cont = cont;
    aux->right == NULL ? cont++ : cont = cont;
    
    return cont;
}

// Complejidad O(n)
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

// Complejidad O(n)
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

// Complejidad O(n)
template<class T>
void BST<T>::print() {
    int level = 0;
    cout << endl;
    printTree(root, level);
    cout << endl;
    
}

// Complejidad O(n)
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
    
    /*  ~~~~~~INTENTO FALLIDO~~~~~
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

// Complejidad O(1)
template<class T>
bool BST<T>::isEmpty() {
    return root == NULL;
}

// Complejidad O(n)
template<class T>
void BST<T>::preOrder(Node<T>* aux) {
    if (aux != NULL) {
        cout << aux->data << " ";
        preOrder(aux->left);
        preOrder(aux->right);
    }
}

// Complejidad O(n)
template<class T>
void BST<T>::inOrder(Node<T>* aux) {
    if (aux != NULL) {
        inOrder(aux->left);
        cout << aux->data << " ";
        inOrder(aux->right);
    }
}

// Complejidad O(n)
template<class T>
void BST<T>::postOrder(Node<T>* aux) {
    if (aux != NULL) {
        postOrder(aux->left);
        postOrder(aux->right);
        cout << aux->data << " ";
    }
}

// Complejidad O(1)
template<class T>
void BST<T>::visit(int order) {
    switch (order) {
        case 1: {
            preOrder(root);
            break;
        }
        case 2: {
            inOrder(root);
            break;
        }
        case 3: {
            postOrder(root);
            break;
        }
        case 4: {
            levelByLevel();
            break;
        }
        case 5: {
            height(root);
            break;
        }
        default:
            break;
    }
}

// Complejidad O(n)
template <class T>
void BST<T>::levelByLevel() {
    if (!isEmpty()) {
        Queue< Node<T>* > queue;
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            Node<T> *aux = queue.dequeue();
            cout << aux->data << " ";
            if (aux->left != NULL) {
                queue.enqueue(aux->left);
            }
            if (aux->right != NULL) {
                queue.enqueue(aux->right);
            }
        }
    }
}

// Complejidad O(n)
template <class T>
void BST<T>::ancestors(T data) {
    if (!isEmpty()) {
        Node<T> *aux = root;
        Stack<T> stack;
        if (aux->data != data) {
            bool notFound = false;
            while (aux->data != data && !notFound ) {
                stack.push(aux->data);
                if (data < aux->data) {
                    if (aux->left == NULL) {
                        notFound = true;
                    } else {
                        aux = aux->left;
                    }
                } else {
                    if (aux->right == NULL) {
                        notFound = true;
                    } else {
                        aux = aux->right;
                    }
                }
            }
            if (!notFound) {
                while (!stack.isEmpty()) {
                    try {
                        T data = stack.pop();
                        cout << data << " ";
                    } catch (runtime_error& e) {
                        cout << e.what() << endl;
                    }
                }
            }
        } else {
            cout << data << " has no ancestors" << endl;
        }
    } else {
        cout << "The BST is empty" << endl;
    }
}

// Complejidad O(n)
template <class T>
int BST<T>::whatLevelAmI(T data) {
    int level = 0;
    if (!isEmpty()) {
        Node<T> *aux = root;
        if (aux->data != data) {
            bool notFound = false;
            while (aux->data != data && !notFound ) {
                level++;
                if (data < aux->data) {
                    if (aux->left == NULL) {
                        notFound = true;
                    } else {
                        aux = aux->left;
                    }
                } else {
                    if (aux->right == NULL) {
                        notFound = true;
                    } else {
                        aux = aux->right;
                    }
                }
            }
            if (!notFound) {
                level++;
            } else {
                level = -1;
            }
        } else {
            level = 1;
        }
    } else {
        level = -1;
    }
    return level;
}

// Complejidad O(n)
template<class T>
int BST<T>::height(Node<T> *node) {
    int h = 0;
    int l,r;
    if (node != NULL) {
        h++;
        l = height(node->left);
        r = height(node->right);
        (l > r) ? h += l : h += r;
    }
    return h;
}

template<class T>
int BST<T>::heightBST() {
    return height(root);
}

// Complejidad O(1)
template<class T>
int BST<T>::childs(Node<T> *node) {
    int numChilds = 0;
    if (node->left != NULL) {
        numChilds++;
    }
    
    if (node->right != NULL) {
        numChilds++;
    }
    return numChilds;
}

#endif /* BST_h */

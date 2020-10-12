//
//  main.cpp
//  BinarySearchTrees
//
//  Created by Diego Solis on 10/9/20.
//

#include <iostream>
using namespace std;
#include "Node.h"
#include "BST.h"

int main() {
    BST<int> diego;
    diego.insert(9);
    diego.insert(7);
    diego.insert(11);
    diego.insert(6);
    diego.insert(8);
    diego.insert(13);
    diego.print();
    diego.removeElement(11);
    diego.print();
    return 0;
}

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
    diego.insert(4);
    diego.insert(6);
    diego.insert(2);
    diego.print();
    return 0;
}

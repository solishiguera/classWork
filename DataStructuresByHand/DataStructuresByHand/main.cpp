//
//  main.cpp
//  dataStructures
//
//  Created by Diego Solis on 10/1/20.
//

#include <iostream>
using namespace std;
#include "Node.h"
#include "LinkedList.h"
#include "Queue.h"


int main() {
    
    LinkedList<int> diego;
    
    /*
    LinkedList<int> lol;
    lol = {1,2,3,4};
    lol.insertAt(2, 34);
    lol.printElements();
    lol.deleteAt(3);
    lol.printElements();
    */
    
    diego.addFirst(4);
    diego.addFirst(67);
    diego.addFirst(873);
    diego.addFirst(14);
    diego.addLast(77);
    diego.printElements();
    
    diego[3] = 100;
    diego.insertAt(5, 67);
    diego.printElements();
    diego.sort();
    diego.printElements();
     
    // cout << diego.findData(4) << endl;
    
    cout << "My queue" << endl;
    Queue<int> myQueue;
    myQueue = {5,6,7,8,9};
    myQueue.printElements();
    cout << myQueue[4] << endl;

    
    
    
    return 0;
}

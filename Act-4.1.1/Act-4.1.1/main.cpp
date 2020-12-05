#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#include "GraphM.h"
#include "Graph.h"

int main() {
    
    /*
     GIT
     cd Documents/TEC/"SEMESTRE 3"/"Estructura de datos"/classWork/Act-4.1.1
     */
    
    vector< vector<int> > list;
    // inicio, destino, peso
    
    //list = {{1,2,8},{1,3,5},{2,3,9},{3,1,8},{3,2,3},{4,1,9},{4,2,7},{4,3,8}};
    
    list = {{0,3,7}, {0,4,2}, {1,3,1}, {1,6,3}, {2,6,8}, {3,0,7}, {3,1,1}, {3,5,4}, {3,7,2}, {4,0,2}, {4,7,5}, {5,3,4}, {5,6,4}, {5,7,6}, {6,1,3}, {6,2,8}, {6,5,4}, {7,3,2}, {7,4,5}, {7,5,6}};
    
    //list = {{0,2,1}, {0,3,7}, {2,0,1}, {2,1,1}, {2,6,3}, {1,2,1}, {1,6,3}, {1,5,4}, {5,1,4}, {5,6,4}, {5,3,7}, {3,0,7}, {3,5,7}, {3,7,1}, {6,2,3}, {6,1,3}, {6,5,4}, {6,4,6}, {6,7,6}, {7,6,6}, {7,3,1}, {4,6,6}};     
    //list = {{0,3,4},{0,4,8},{1,6,5},{2,6,9},{3,7,8},{4,2,3},{5,1,9},{5,6,7},{5,7,8},{7,5,9}};
    
    Graph<int> graph(list);
    
    GraphM<int> graphM(list);
    
    cout << endl << "Matriz de adyacencias" << endl << endl;
    graphM.print();
    cout << endl << "BFS" << endl << endl;
    graphM.bfs();
    
    cout << endl << "DFS" << endl << endl;
    graphM.dfs();
    
    cout << endl << "List de adyacencias" << endl << endl;
    graph.print();
    
    cout << endl << "Shortest Path" << endl << endl;
    graph.shortestPath(3);
    return 0;
}

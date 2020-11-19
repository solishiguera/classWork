//
//  Graph.h
//  Act-4.1.1
//
//  Created by Diego Solis on 11/4/20.
//

#ifndef Graph_h
#define Graph_h

template<class T>
class Graph {
private:
    vector< vector<T> > adjList;
    vector<T> vertices;
    int qtyVertices;
    int qtyEdges;
    int findVertex(T vertex);
public:
    Graph(vector< vector<T> > list, int qtyVertices, int qtyEdges);
    void print();
};

template<class T>
Graph<T>::Graph(vector< vector<T> > list, int qtyVertices, int qtyEdges) {
    this-> list = list;
    this-> qtyVertices = qtyVertices;
    this-> qtyEdges = qtyEdges;
    int source = 0;
    int target = 1;
    
    // crear lista de vértices
    for(auto edge: list) {
        T temp = edge[source];
        int pos = findVertex(temp);
        if (pos >= 0) {
            adjList[pos].push_back(edge[target]);
        } else {
            vertices.push_back(temp);
            adjList.push_back(edge);
        }
    }
    
    // ordenar lista de vértices
    sort(vertices.begin(), vertices.end());
    
    // agregar los vértices a la lista de adyacencias
    for (auto vertex : vertices) {
        vector<T> temp;
        temp.push_back(vertex);
        adjList.push_back(temp);
    }
    
    // agregar los detinos a la lista de adyacencias
    for (auto edge : list) {
        int pos = findVertex(edge[source]);
        adjList[pos].push_back(edge[target]);
    }
    
}

template<class T>
int Graph<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1; 
    }
}

#endif /* Graph_h */

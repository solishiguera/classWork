//
//  Graph.h
//  Act-4.2
//
//  Created by Diego Solis on 12/6/20.
//

#ifndef Graph_h
#define Graph_h

template<class T>
struct Edge {
    T target;
    int weight;
};

template<class T>
class Graph {
private:
    vector< vector< Edge<T> > > adjList;
    vector<T> vertices;
    int findVertex(T vertex);
    int size;
    void dfsR(T vertex, vector<bool> &status);
    int minWeight(vector<int> weight, vector<bool> status);
    void topologicalSortR(int vertex, vector<bool> &status, stack<T> &Stack);
    bool bipartiteGraphR(int num, vector<int> &color, vector<bool> &status);
public:
    Graph(vector< vector<T> > list);
    void topologicalSort(); // Complejidad O(log(n))
    void bfs(T vertex);
    void dfs(T vertex);
    void shortestPath(T vertex);
    void print();
    bool bipartiteGraph();
};

template<class T>
Graph<T>::Graph(vector< vector<T> > list) {
    int source = 0; // Me permite determinar la fuente {{'a','b'}} -> la 'a' es fuente
    int target = 1; // Me permite determinar el destino {{'a','b'}} -> la 'b' es destino
    int weight = 2;
    //vector<T> edge;
    
    // Crear lista de vertices
    for (vector<T> edge: list) {
        // Iterar en toda mi lista
        T temp = edge[source];
        int pos = findVertex(temp);
        if (pos < 0) {
            vertices.push_back(temp);
        }
        temp = edge[target];
        pos = findVertex(temp);
        if (pos < 0) {
            vertices.push_back(temp);
        }
        
    }
    
    size = (int) vertices.size();
    // Ordenar la lista de vertices
    sort(vertices.begin(), vertices.end());
    
    //vector< Edge<T> > edgeTemp;
    vector< vector< Edge<T> > > tempList(size);
    adjList = tempList;
    
    // Agregar los vertices adyacentes a la lista de adyacencias
    for (auto path : list) {
        int pos = findVertex(path[source]);
        Edge<T> edge;
        edge.target = path[target];
        edge.weight = path[weight];
        adjList[pos].push_back(edge);
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

template<class T>
void Graph<T>::print() {
    for (int v = 0; v < size; v++) {
        cout << vertices[v] << "-> ";
        for (auto path : adjList[v]) {
            cout << path.target << " " << path.weight << " ";
        }
        cout << endl;
    }
}

template<class T>
void Graph<T>::bfs(T vertex) {
    int pos = findVertex(vertex);
    if (pos >= 0) {
        vector<bool> status(size,false);
        queue<int> q;
        // agregamos el primer vertice a la fila
        q.push(pos);
        // Le cambiamos el status al primer vértice
        status[pos] = true;
        while (!q.empty()) {
            int vertex = q.front();
            cout << vertices[vertex] << " ";
            for (auto adj : adjList[vertex]) {
                int posAdj = findVertex(adj.target);
                if (!status[posAdj]) {
                    q.push(posAdj);
                    status[posAdj] = true;
                }
            }
            q.pop();
        }
        cout << endl;
    }
}


template<class T>
void Graph<T>::dfs(T vertex) {
    int pos = findVertex(vertex);
    if (pos >= 0) {
        vector<bool> status(vertices.size(),false);
        dfsR(vertices[0],status);
        cout << endl;
    }
}


template<class T>
void Graph<T>::dfsR(T vertex, vector<bool> &status) {
    int pos = findVertex(vertex);
    if (!status[pos]) {
        cout << vertex << " ";
        status[pos] = true;
        for (auto adj : adjList[pos]) {
            int posAdj = findVertex(adj.target);
            if (!status[posAdj]) {
                dfsR(adj.target,status);
            }
        }
    }
}

template<class T>
int Graph<T>::minWeight(vector<int> weight, vector<bool> status) {
    //priority_queue <int, vector<int>, greater<int> > pq;
    int minWeight = INT_MAX;
    int minVertex = -1;
    for (int v = 0; v < size; v++) {
        if (!status[v]) { // Si status en posición v NO es Verdadero
            if (minWeight > weight[v]) { // Si el minweight es mayor a weight en posición V
                minWeight = weight[v]; // minweight ahora es igual a weight en posición V
                minVertex = v; // minVertex ahora es igual a v
            }
        }
    }
    return minVertex;
}

template<class T>
void Graph<T>::shortestPath(T vertex) {
    int pos = findVertex(vertex);
    
    if (pos >= 0) {
        vector<bool> status(size, false);
        vector<int> weight(size, INT_MAX); // INT_MAX es el infinito
        vector<int> path(size, -1);
        weight[pos] = 0;
        int next = minWeight(weight, status);
        while (next >= 0) {
            status[next] = true;
            for (int a = 0; a < adjList[next].size(); a++) {
                int posAdj = findVertex(adjList[next][a].target);
                if (!status[posAdj]) {
                    if (weight[posAdj] > weight[next] + adjList[next][a].weight) {
                        weight[posAdj] = weight[next] + adjList[next][a].weight;
                        path[posAdj] = next;
                    }
                }
            }
            next = minWeight(weight, status);
        }
        
        for (int v = 0; v < size; v++) {
            stack<int> sp;
            sp.push(v);
            int p = path[v];
            while (p >= 0) {
                sp.push(p);
                p = path[p];
            }
            
            while (!sp.empty()) {
                cout << vertices[sp.top()] << " ";
                sp.pop();
            }
            
            cout << "weight: " << weight[v] << endl;
        }
    }
}

// Complejidad O(log(n))
template<class T>
void Graph<T>::topologicalSort(){
    stack<T> Stack;
    vector<bool> status(vertices.size(), false);
    for(int i = 0; i< vertices.size(); i++){
        if(!status[i] && adjList[i].size() > 0)
        {
            topologicalSortR(i, status, Stack);
            Stack.push(vertices[i]);
        }
    }
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Complejidad O(n)
template<class T>
void Graph<T>::topologicalSortR(int vertex, vector<bool> &status, stack<T> &Stack) {
    status[vertex] = true;
    for (auto adj : adjList[vertex]){
        int posAdj = findVertex(adj.target);
        if(!status[posAdj]){
            topologicalSortR(posAdj, status, Stack);
            Stack.push(adj.target);
        }
    }
}

// Complejidad O(n^2)
template<class T>
bool Graph<T>::bipartiteGraph() { // Similar al de matrices
    vector<int> color(vertices.size(),-1);
    vector<bool> status(vertices.size(), false);
    color[0] = 0;
    status[0] = true;
    if(bipartiteGraphR(0, color, status))
    {
        return true;
    }
    return false;
}

// complejidad: O(n^2)
template<class T>
bool Graph<T>::bipartiteGraphR(int num, vector<int> &color, vector<bool> &status) {
    for(int i = 0; i < adjList[num].size(); i++) { // Similar al de Matrices
        int pos = findVertex(adjList[num][i].target);
        if(!status[pos]) {
            status[pos] = true;
            if(color[num] == 0) {
                color[pos] = 1;
            } else {
                color[pos] = 0;
            }
            
            if(!bipartiteGraphR(pos, color, status)) {
                return false;
            }
        }
        else {
            if(color[pos] == color[num]) {
                return false;
            }
        }
    }
    return true;
}

// Topological hay q usar el dfs
// mod dfs porque recorremos todos los vértices

#endif

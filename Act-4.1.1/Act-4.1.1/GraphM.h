#ifndef GraphM_h
#define GraphM_h

template<class T>
class GraphM {
private:
    vector< vector<int> > adjMatrix;
    vector<T> vertices;
    int findVertex(T vertex);
    void dfsR(T vertex, vector<bool> &status);
public:
    GraphM(vector< vector<T> > list);
    void print();
    void bfs();
    void dfs();
};

template<class T>
GraphM<T>::GraphM(vector< vector<T> > list) {
    // Crear lista de vertices
    int source = 0;
    int target = 1;
    int weight = 2;
    for (vector<T> edge : list) {
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

    // Ordenar la lista de vertices
    sort(vertices.begin(), vertices.end());

    // Inicializar la matriz con -1
    for (auto vertex : vertices) {
        vector<int> temp(vertices.size(),-1);
        adjMatrix.push_back(temp);
    }

    // Actualizar matriz de adyacencias
    for (auto edge : list) {
        int posSource = findVertex(edge[source]);
        int posTarget = findVertex(edge[target]);
        adjMatrix[posSource][posTarget] = edge[weight];
    }
}

template<class T>
int GraphM<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template<class T>
void GraphM<T>::print() {
    cout << "  ";
    for (auto v : vertices) {
        cout << v << " ";
    }
    cout << endl;
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " ";
        for (int j=0; j<vertices.size(); j++) {
            if (adjMatrix[i][j]>=0) {
                cout << adjMatrix[i][j] << " ";
            } else {
                cout << " " << " ";
            }
        }
        cout << endl;
    }
}

template<class T>
void GraphM<T>::bfs() {
    vector<bool> status(vertices.size(),false);
    queue<T> q;
    // agregamos el primer vertice a la fila
    q.push(vertices[0]);
    // Le cambiamos el status al primer vértice
    status[0] = true;
    while (!q.empty()) {
        T vertex = q.front();
        cout << vertex << " ";
        int pos = findVertex(vertex);
        for (int adj=0;adj<vertices.size();adj++) {
            if (adjMatrix[pos][adj]>=0) {
                if (!status[adj]) {
                    q.push(vertices[adj]);
                    status[adj] = true;
                }
            }
        }
        q.pop();
    }
    cout << endl;
}

template<class T>
void GraphM<T>::dfs() {
    vector<bool> status(vertices.size(),false);
    dfsR(vertices[0],status);
    cout << endl;
}

template<class T>
void GraphM<T>::dfsR(T vertex, vector<bool> &status) {
    int pos = findVertex(vertex);
    if (!status[pos]) {
        cout << vertex << " ";
        status[pos] = true;
        for (int adj=0; adj<vertices.size();adj++) {
            if (adjMatrix[pos][adj]>=0) {
                if (!status[adj]) {
                    dfsR(vertices[adj],status);
                }
            }
        }
    }
}


#endif

#ifndef GraphM_h
#define GraphM_h

template<class T>
class GraphM {
private:
    vector< vector<int> > adjMatrix;
    vector<T> vertices;
    int size; 
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
    int source = 0; // Pos 0
    int target = 1; // Pos 1
    int weight = 2; // Pos 2
    
    
    // list = {{0,3,4},{0,4,8},{1,6,5},{2,6,9},{3,7,8},{4,2,3},{5,1,9},{5,6,7},{5,7,8},{7,5,9}};
    // Crear lista de vértices
    for (vector<T> edge : list) { // Lo que hace es darle los valores de la primera {{lista}}
        T temp = edge[source]; // Aquí el valor sería 0 porque es el origen
        int pos = findVertex(temp); // se busca posición de este elemento
        if (pos < 0) { // Si no está dentro del vector de vértices, se agrega (daría -1 por eso < 0)
            vertices.push_back(temp); // Se agrega a lista de vértices
        }
        temp = edge[target]; // Ahora temp es igual a Destino
        pos = findVertex(temp); // Se busca posición de temp, que es destino
        if (pos < 0) { // Si no está, lo agrega, de lo contrario, no lo agrega
            // Esto es lo que permita que no se repitan valores
            vertices.push_back(temp); // Se agrega a lista de vértices
        }
    }

    size = (int) vertices.size(); // Cantida de vértices de mi grafo
    // Ordenar la lista de vertices
    sort(vertices.begin(), vertices.end());

    // Inicializar la matriz con -1
    for (auto vertex : vertices) {
        vector<int> temp(vertices.size(),-1);
        adjMatrix.push_back(temp);
    }

    // Actualizar matriz de adyacencias
    for (auto edge : list) { // Se le dan valores de lista a vector edge
        int posSource = findVertex(edge[source]); // Se busca posición origen dentro de vector edge
        int posTarget = findVertex(edge[target]); // Se busca posición destino dentro de vector edge
        adjMatrix[posSource][posTarget] = edge[weight]; // en la posición de matriz posSource,posTarget de agrega peso
    }
}

template<class T>
int GraphM<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex); // Se busca elemento ingresado
    if (it != vertices.end()) { // Valida que lo encontró
        return it - vertices.begin(); // Regrega posición
    } else {
        return -1; // Si no regresa -1
    }
}

template<class T>
void GraphM<T>::print() {
    cout << "  ";
    for (auto v : vertices) {
        cout << v << " "; // Imprime renglón de arriba
    }
    
    cout << endl;
    for (int i = 0; i < vertices.size(); i++) { // i es iterador de todo mi vector
        cout << vertices[i] << " "; // Imprime la columna de lado izquierdo
        for (int j = 0; j < vertices.size(); j++) {
            if (adjMatrix[i][j] >= 0) { // Si la adjMatrix en pos i,j es mayor o igual a 0,
                cout << adjMatrix[i][j] << " ";
            } else {
                cout << "-" << " ";
            }
        }
        cout << endl;
    }
    
}

template<class T>
void GraphM<T>::bfs() {
    vector<bool> status(size,false); // Creamos vector llamado status, mismo tamaño q cant vértices, elementos en false
    queue<T> q;
    // agregamos el primer vertice a la fila
    q.push(vertices[0]);
    // Le cambiamos el status al primer vértice
    status[0] = true; // Lo ponemos en true para ya no procesarlo
    
    while (!q.empty()) { // Mientras que queue no esté vacía
        T vertex = q.front(); // vertex es igual a primer elemento de fila
        cout << vertex << " "; // Se imprime elemento
        int pos = findVertex(vertex); // Se busca la posición de primer vértice
        for (int adj = 0; adj < size; adj++) { // Menor que cantidad de vértices
            if (adjMatrix[pos][adj] >= 0) { // Si pos,adj es mayor o igual a 0
                if (!status[adj]) { // Si mi vector de estatus es falso
                    q.push(vertices[adj]); // Se agrega siguiente elemento a fila
                    status[adj] = true; // Status en posición de adj se vuelve true
                }
            }
        }
        q.pop(); // Se saca primer elemento de fila
    }
    cout << endl;
}

template<class T>
void GraphM<T>::dfs() {
    vector<bool> status(vertices.size(),false); // Creamos un vector llamado status
    dfsR(vertices[0],status); // Se manda primer vértice y vector de status
    cout << endl;
}

template<class T>
void GraphM<T>::dfsR(T vertex, vector<bool> &status) {
    int pos = findVertex(vertex);  // Pos es igual a posición de vértice actual
    if (!status[pos]) { // Si es falso entro al condicional
        cout << vertex << " "; // Imprimo vértice
        status[pos] = true; // Lo pongo en true
        for (int adj = 0; adj < size; adj++) {
            if (adjMatrix[pos][adj] >= 0) {
                if (!status[adj]) {
                    dfsR(vertices[adj],status);
                }
            }
        }
    }
    
}


#endif

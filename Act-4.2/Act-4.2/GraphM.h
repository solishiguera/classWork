//
//  GraphM.h
//  Act-4.2
//
//  Created by Diego Solis on 12/6/20.
//

#ifndef GraphM_h
#define GraphM_h

template<class T>
class GraphM {
private:
    vector< vector<int> > adjMatrix;
    vector<T> vertices;
    int size;
    int findVertex(T vertex); // Complejidad O(n)
    void dfsR(T vertex, vector<bool> &status); // Complejidad O(n)
    int minWeight(vector<int> weight, vector<bool> status); // Complejidad O(log(n))
    bool bipartiteGraphR(int num, vector<int> &color, vector<bool> &status); // Complejidad O(n^2)
    void topologicalSortR(int vertex, vector<bool> &status, stack<T> &Stack); // Complejidad O(n)
public:
    GraphM(vector< vector<T> > list);
    void print(); // Complejidad O(n^2)
    void bfs(T vertex);  // Complejidad O(n^2)
    void dfs(T vertex); // Complejidad O(log(n))
    void shortestPath(T vertex); // Complejidad O(n^2)
    bool bipartiteGraph(); // Complejidad O(n^2)
    void topologicalSort(); // Complejidad O(log(n))
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

// Complejidad O(n)
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

// Complejidad O(n^2)
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

// Complejidad O(n^2)
template<class T>
void GraphM<T>::bfs(T vertex) {
    vector<bool> status(size,false); // Creamos vector llamado status, mismo tamaño q cant vértices, elementos en false
    queue<T> q;
    
    int pos = findVertex(vertex);
    if(vertex >= 0) { // Si vértice es mayor/igual a 0
        q.push(vertices[pos]); // Se agrega vértice a fila
        status[pos] = true; // Se pone status en verdadero
    }
    
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

// Complejidad O(log(n))
template<class T>
void GraphM<T>::dfs(T vertex) {
    vector<bool> status(vertices.size(),false); // Creamos un vector llamado status
    int pos = findVertex(vertex);
    if(pos >= 0) { // Si pos es mayor o igual que 0
        vector<bool> status(vertices.size(), false);
        dfsR(vertices[pos], status); // Se manda primer vértice y vector de status
    }
    cout << endl;
}

// Complejidad O(n)
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

// Complejidad O(n^2)
template<class T>
void GraphM<T>::shortestPath(T vertex) {
    int pos = findVertex(vertex);
    
    if (pos >= 0) {
        vector<bool> status(size, false);
        vector<int> weight(size, INT_MAX); // INT_MAX es el infinito
        vector<int> path(size, -1);
        weight[pos] = 0;
        int next = minWeight(weight, status);
        
        while(next >= 0) { // Puede ser -1
            status[next] = true;
            for(int i = 0; i < adjMatrix[next].size(); i++){
                if(adjMatrix[next][i] >= 0){
                    int posAdj = findVertex(i); // Se busca vértice en posición i
                    if(!status[posAdj]) {
                        if(weight[posAdj] > weight[next] + adjMatrix[next][i]){
                            weight[posAdj] = weight[next] + adjMatrix[next][i];
                            path[posAdj] = next;
                        }
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
int GraphM<T>::minWeight(vector<int> weight, vector<bool> status) {
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

// Complejidad O(n^2)
template<class T>
bool GraphM<T>::bipartiteGraph(){
    vector<int> color(vertices.size(),-1); // Creamos vector llamado color, con -1
    vector<bool> status(vertices.size(), false); // Se crea vector en status; inicia en false
    color[0] = 0; // Primera posic es 0
    status[0] = true; // Status en primera posic es verdadero
    if(bipartiteGraphR(0, color, status)) { // Si es bipartita regresa verdadero
        return true;
    }
    return false;
}

// Complejidad O(n^2)
template<class T>
bool GraphM<T>::bipartiteGraphR(int num, vector<int> &color, vector<bool> &status) {
    
    for(int i = 0; i < adjMatrix[num].size(); i++){
        if(adjMatrix[num][i] >= 0) { // Si el número en posicion num, i es 0
            if(!status[i]) { // Si status NO es verdadero
                status[i] = true; // Se coloca como verdadero
                if (color[num] == 0) { // Si es 0 se coloca en 1
                    color[i] = 1; 
                } else { // De lo contrario se coloca en 0
                    color[i] = 0;
                }
                
                if(!bipartiteGraphR(i, color, status)) { // Si NO es bipartita, no se cumple condición del otro método
                    return false; // Regresa falso
                }
            } else {
                if(color[i] == color[num]) { // Si no, si el color en i es igual a color en num
                    return false; // Regresa falso
                }
            }
        }
    }
    return true; // De lo contrario, regresa true
}

// Complejidad O(log(n))
template<class T>
void GraphM<T>::topologicalSort(){
    stack<T> Stack;
    vector<bool> status(vertices.size(), false); // Se crea vector status, falso
    for(int i = 0; i < vertices.size(); i++) {
        if(!status[i]) { // Si status NO es verdadero
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
void GraphM<T>::topologicalSortR(int vertex, vector<bool> &status, stack<T> &Stack){
    status[vertex] = true;
    for (int i = 0; i < adjMatrix[vertex].size(); i++){
        if(adjMatrix[vertex][i] >=0){
            if(!status[i]){
                topologicalSortR(i, status, Stack);
                Stack.push(vertices[i]);
            }
        }
    }
}



#endif

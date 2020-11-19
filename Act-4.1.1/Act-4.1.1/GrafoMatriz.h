//
//  GrafoMatriz.h
//  Act-4.1.1
//
//  Created by Diego Solis on 11/4/20.
//

#ifndef GrafoMatriz_h
#define GrafoMatriz_h

template<class T>
class GrafoMatriz {
private:
    vector< vector<bool> > listaAdyac;
    vector<T> vertices;
    int cantVertices, cantArcos;
public:
    GrafoMatriz();
    GrafoMatriz(vector< vector<T> > listaAdyac, int cantVertices, int cantArcos);
    void printListaAdy();
};

template<class T>
GrafoMatriz<T>::GrafoMatriz(vector< vector<T> > listaAdyac, int cantVertices, int cantArcos) {
    this-> cantVertices = cantVertices;
    this-> cantArcos = cantArcos;
    
    /* Inicializar matriz, hacerlo en menos líneas */
    // FALTA TYPENAME EN ITERATOR
    for (int i = 0; i < cantVertices; i++) {
        vector<bool> vectorTemp;
        for (int j = 0; j < cantVertices; j++) {
            vectorTemp.push_back(false);
        }
        listaAdyac.push_back(vectorTemp);
    }
    
    
}

template<class T>
void GrafoMatriz<T>::printListaAdy() {
}

#endif /* GrafoMatriz_h */

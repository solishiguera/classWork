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
    this-> listaAdyac = listaAdyac;
    this-> cantVertices = cantVertices;
    this-> cantArcos = cantArcos;
}

template<class T>
void GrafoMatriz<T>::printListaAdy() {
    for (int i = 0; i < cantVertices; i++) {
        cout << i << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < listaAdyac.size(); i++) {
        cout << listaAdyac[i][0] << ": ";
        for (int j = 1; j < listaAdyac[i].size(); j++) {
            cout << "\t" << listaAdyac[i][j];
        }
        cout << endl;
    }
}

#endif /* GrafoMatriz_h */

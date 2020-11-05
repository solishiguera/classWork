//
//  GrafoLista.h
//  Act-4.1.1
//
//  Created by Diego Solis on 11/4/20.
//

#ifndef GrafoLista_h
#define GrafoLista_h

template<class T>
class GrafoLista {
private:
    vector< vector<T> > listaAdyac;
    int cantVertices, cantArcos;
public:
    GrafoLista();
    GrafoLista(vector< vector<T> > listaAdyac, int cantVertices, int cantArcos);
    void printListaAdy();
};

template<class T>
GrafoLista<T>::GrafoLista(vector< vector<T> > listaAdyac, int cantVertices, int cantArcos) {
    this-> listaAdyac = listaAdyac;
    this-> cantVertices = cantVertices;
    this-> cantArcos = cantArcos;
}

template<class T>
void GrafoLista<T>::printListaAdy() {
    for (int i = 0; i < listaAdyac.size(); i++) {
        cout << listaAdyac[i][0] << ": ";
        for (int j = 1; j < listaAdyac[i].size(); j++) {
            cout << "\t" << listaAdyac[i][j];
        }
        cout << endl;
    }
}



#endif /* GrafoLista_h */

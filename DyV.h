#ifndef DYV_H
#define DYV_H

#include <vector>

using namespace std;

template<typename T>

int BusquedaBinaria(T X, const vector<T>& V, int ini, int fin){
    if(ini > fin){
        return -1;
    }

    int medio = (ini + fin) / 2;

    if(V[medio] == X){
        return medio;
    }else if(V[medio] < X){
        return BusquedaBinaria(X, V, medio + 1, fin);
    }else{
        return BusquedaBinaria(X, V, ini, medio - 1);
    }
}



template<typename T>

int BusquedaBinaria_INV(T X, const vector<T>& V, int ini, int fin){
    if(ini > fin){
        return -1;
    }

    int medio = (ini + fin) / 2;

    if(V[medio] == X){
        return medio;
    }else if(V[medio] > X){
        return BusquedaBinaria_INV(X, V, medio + 1, fin);
    }else{
        return BusquedaBinaria_INV(X, V, ini, medio - 1);
    }
}



#endif

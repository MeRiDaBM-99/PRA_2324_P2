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



//versiones alernativas de Partition (cambiar el pivote al principio)
template<typename T>
int Partition_inicio(vector<T>& V, int ini, int fin){
    T x = V[ini];
    int i = ini + 1;
    for(int j = ini + 1; j <= fin; j++){
        if(V[j] < x){
            T aux = V[j];
            V[j] = V[i];
            V[i] = aux;
            i = i + 1;
        }
    }
    T aux_ = V[i - 1];
    V[i - 1] = V[ini];
    V[ini] = aux_;

    return i - 1;

}

template<typename T>
void QuickSort_inicio(vector<T>& V, int ini, int fin){
    if(ini < fin){
        int pivot = Partition_inicio(V, ini, fin);
        QuickSort_inicio(V, ini, pivot - 1);
        QuickSort_inicio(V, pivot + 1, fin);
    }
}



//Programa QuickSort

template<typename T>
int Partition(vector<T>& V, int ini, int fin){
    T x = V[fin];
    int i = ini;
    for(int j = ini; j < fin; j++){
        if(V[j] <= x){
            T aux = V[j];
            V[j] = V[i];
            V[i] = aux;
            i = i + 1;
        }
    }
    T aux_ = V[i];
    V[i] = V[fin];
    V[fin] = aux_;

    return i;

}

template<typename T>
void QuickSort(vector<T>& V, int ini, int fin){
    if(ini < fin){
        int pivot = Partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
    }
}


#endif

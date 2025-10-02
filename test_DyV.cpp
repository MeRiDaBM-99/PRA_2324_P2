#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "DyV.h"

using namespace std;

// Función auxiliar para imprimir resultados de las pruebas
void imprimirResultado(string tipo, string valorBuscado, int resultado, int esperado) {
    cout << "Busqueda de " << valorBuscado << " en vector de " << tipo << ": ";
    if (resultado == esperado) {
        cout << "CORRECTO - Posicion: " << resultado << endl;
    } else {
        cout << "ERROR - Esperado: " << esperado << ", Obtenido: " << resultado << endl;
    }
}

int main() {
    cout << "======== Busqueda binaria en orden ascendente ========" << endl;

    cout << "--- PRUEBAS CON ENTEROS (int) ---" << endl;
    vector<int> enteros = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    
    cout << "Vector: ";
    for (int num : enteros) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    // Buscar elementos que SÍ están
    imprimirResultado("int", "23", BusquedaBinaria(23, enteros, 0, 10), 5);
    imprimirResultado("int", "45", BusquedaBinaria(45, enteros, 0, 10), 7);
    
    // Buscar elementos que NO están
    imprimirResultado("int", "10", BusquedaBinaria(10, enteros, 0, 10), -1);
    imprimirResultado("int", "1", BusquedaBinaria(1, enteros, 0, 10), -1);
    
    cout << endl;
   




    
    cout << "--- PRUEBAS CON FLOTANTES (float) ---" << endl;
    vector<float> flotantes = {1.5f, 2.3f, 3.7f, 5.1f, 8.9f, 12.4f, 15.6f};
    
    cout << "Vector: ";
    for (float num : flotantes) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    imprimirResultado("float", "5.1", BusquedaBinaria(5.1f, flotantes, 0, 6), 3);
    imprimirResultado("float", "7.0", BusquedaBinaria(7.0f, flotantes, 0, 6), -1);
    
    cout << endl;
    
    
    
    
    
    
    cout << "--- PRUEBAS CON CARACTERES (char) ---" << endl;
    vector<char> caracteres = {'a', 'c', 'e', 'g', 'i', 'k', 'm', 'o', 'q'};
    
    cout << "Vector: ";
    for (char c : caracteres) {
        cout << c << " ";
    }
    cout << endl << endl;
    
    imprimirResultado("char", "'e'", BusquedaBinaria('e', caracteres, 0, 8), 2);
    imprimirResultado("char", "'q'", BusquedaBinaria('q', caracteres, 0, 8), 8);
    imprimirResultado("char", "'b'", BusquedaBinaria('b', caracteres, 0, 8), -1);
    
    cout << endl;
    
    
    
    
    
    
    cout << "--- PRUEBAS CON CADENAS (string) ---" << endl;
    vector<string> palabras = {"alba", "casa", "dado", "elfo", "gato", "lobo", "mesa", "oso"};
    
    cout << "Vector: ";
    for (string palabra : palabras) {
        cout << palabra << " ";
    }
    cout << endl << endl;
    
    imprimirResultado("string", "gato", BusquedaBinaria(string("gato"), palabras, 0, 7), 4);
    imprimirResultado("string", "alba", BusquedaBinaria(string("alba"), palabras, 0, 7), 0);
    imprimirResultado("string", "perro", BusquedaBinaria(string("perro"), palabras, 0, 7), -1);
    
    cout << endl;
    
    
    
    
    
    
    
    cout << "--- PRUEBAS CON DOBLES (double) ---" << endl;
    vector<double> dobles = {1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
    
    cout << "Vector: ";
    for (double num : dobles) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    imprimirResultado("double", "5.55", BusquedaBinaria(5.55, dobles, 0, 8), 4);
    imprimirResultado("double", "1.11", BusquedaBinaria(1.11, dobles, 0, 8), 0);
    imprimirResultado("double", "6.00", BusquedaBinaria(6.00, dobles, 0 ,8), -1);
    
    cout << endl;
    
    
    
    
    
    
    // Vector con un solo elemento
    vector<int> unElemento = {42};
    cout << "Vector de un elemento: ";
    imprimirResultado("int", "42", BusquedaBinaria(42, unElemento, 0, 0), 0);
    imprimirResultado("int", "10", BusquedaBinaria(10, unElemento, 0, 0), -1);
    
    // Vector con dos elementos
    vector<int> dosElementos = {10, 20};
    cout << "Vector de dos elementos: ";
    imprimirResultado("int", "10", BusquedaBinaria(10, dosElementos, 0, 1), 0);
    imprimirResultado("int", "20", BusquedaBinaria(20, dosElementos, 0, 1), 1);






    cout << endl << endl << endl;
    cout << "======== Busqueda binaria en orden descendente ========" << endl;
    cout << "--- PRUEBAS CON ENTEROS (int) ---" << endl;
    reverse(enteros.begin(), enteros.end());

    cout << "Vector: ";
    for (int num : enteros) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Buscar elementos que SÍ están
    imprimirResultado("int", "23", BusquedaBinaria_INV(23, enteros, 0, 10), 5);
    imprimirResultado("int", "45", BusquedaBinaria_INV(45, enteros, 0, 10), 3);

    // Buscar elementos que NO están
    imprimirResultado("int", "10", BusquedaBinaria_INV(10, enteros, 0, 10), -1);;
    imprimirResultado("int", "1", BusquedaBinaria_INV(1, enteros, 0, 10), -1);

    cout << endl;


    cout << "--- PRUEBAS CON FLOTANTES (float) ---" << endl;
    reverse(flotantes.begin(), flotantes.end());

    cout << "Vector: ";
    for (float num : flotantes) {
        cout << num << " ";
    }
    cout << endl << endl;

    imprimirResultado("float", "5.1", BusquedaBinaria_INV(5.1f, flotantes, 0, 6), 3);
    imprimirResultado("float", "7.0", BusquedaBinaria_INV(7.0f, flotantes, 0, 6), -1);

    cout << endl;


    cout << "--- PRUEBAS CON CARACTERES (char) ---" << endl;
    reverse(caracteres.begin(), caracteres.end());

    cout << "Vector: ";
    for (char c : caracteres) {
        cout << c << " ";
    }
    cout << endl << endl;

    imprimirResultado("char", "'e'", BusquedaBinaria_INV('e', caracteres, 0, 8), 6);
    imprimirResultado("char", "'q'", BusquedaBinaria_INV('q', caracteres, 0, 8), 0);
    imprimirResultado("char", "'b'", BusquedaBinaria_INV('b', caracteres, 0, 8), -1);


    cout << endl;


    cout << "--- PRUEBAS CON CADENAS (string) ---" << endl;
    reverse(palabras.begin(), palabras.end());

    cout << "Vector: ";
    for (string palabra : palabras) {
        cout << palabra << " ";
    }
    cout << endl << endl;

    imprimirResultado("string", "gato", BusquedaBinaria_INV(string("gato"), palabras, 0, 7), 3);
    imprimirResultado("string", "alba", BusquedaBinaria_INV(string("alba"), palabras, 0, 7), 7);
    imprimirResultado("string", "perro", BusquedaBinaria_INV(string("perro"), palabras, 0, 7), -1);

    cout << endl;


    cout << "--- PRUEBAS CON DOBLES (double) ---" << endl;
    reverse(dobles.begin(), dobles.end());

    cout << "Vector: ";
    for (double num : dobles) {
        cout << num << " ";
    }
    cout << endl << endl;

    imprimirResultado("double", "5.55", BusquedaBinaria_INV(5.55, dobles, 0, 8), 4);
    imprimirResultado("double", "1.11", BusquedaBinaria_INV(1.11, dobles, 0, 8), 8);
    imprimirResultado("double", "6.00", BusquedaBinaria_INV(6.00, dobles, 0 ,8), -1);

    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

struct Nodo {
    int fila;
    int columna;
    int valor;
    Nodo* siguiente;
};

void agregarNodo(Nodo*& cabeza, int fila, int columna, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->fila = fila;
    nuevo->columna = columna;
    nuevo->valor = valor;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void calcularSumaPorFila(Nodo* cabeza, int filas, int* sumaFilas) {
    // Inicializar el arreglo de sumas
    for (int i = 0; i < filas; ++i) {
        sumaFilas[i] = 0;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        sumaFilas[actual->fila] += actual->valor;
        actual = actual->siguiente;
    }
}

void determinarFilaMayor(int* sumaFilas, int filas) {
    int sumaMayor = 0;

    for (int i = 0; i < filas; ++i) {
        if (sumaFilas[i] > sumaMayor) {
            sumaMayor = sumaFilas[i];
        }
    }

    cout << "Fila(s) con la suma mayor (" << sumaMayor << "): ";
    for (int i = 0; i < filas; ++i) {
        if (sumaFilas[i] == sumaMayor) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    Nodo* lista = nullptr;

    int filas = 5;
    int columnas = 7;

    agregarNodo(lista, 1, 2, 9);
    agregarNodo(lista, 2, 1, 11);
    agregarNodo(lista, 2, 4, 23);
    agregarNodo(lista, 3, 0, 45);
    agregarNodo(lista, 4, 2, 2);
    agregarNodo(lista, 4, 5, 18);

    int* sumaFilas = new int[filas];
    calcularSumaPorFila(lista, filas, sumaFilas);

    determinarFilaMayor(sumaFilas, filas);

    delete[] sumaFilas;
    while (lista != nullptr) {
        Nodo* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    return 0;
}
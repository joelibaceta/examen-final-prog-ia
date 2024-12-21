#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "Vector.h"
#include "ExcepcionVectorRango.h"

template <typename T, long tam>
Vector<T, tam>::Vector() : nelem(0) {}

template <typename T, long tam>
Vector<T, tam>::~Vector() {
    nelem = 0;
}

template <typename T, long tam>
bool Vector<T, tam>::addElement(const T& elem) {
    if (nelem < tam) {
        array[nelem++] = elem;
        return true;
    }
    return false;
}

template <typename T, long tam>
bool Vector<T, tam>::buscar(const T& elem) const {
    for (int i = 0; i < nelem; ++i) {
        if (array[i] == elem) {
            return true;
        }
    }
    return false;
}

template <typename T, long tam>
bool Vector<T, tam>::eliminar(const T& elem) {
    for (int i = 0; i < nelem; ++i) {
        if (array[i] == elem) {
            for (int j = i; j < nelem - 1; ++j) {
                array[j] = array[j + 1];
            }
            --nelem;
            return true;
        }
    }
    return false;
}

template <typename T, long tam>
T Vector<T, tam>::operator[](int n) const {
    if (n < nelem) {
        return array[n];
    }
    throw ExcepcionVectorRango(n, nelem);
}

template <typename T, long tam>
bool Vector<T, tam>::operator==(const Vector<T, tam>& other) const {
    if (nelem != other.nelem) {
        return false;
    }
    for (int i = 0; i < nelem; ++i) {
        if (array[i] != other.array[i]) {
            return false;
        }
    }
    return true;
}

template <typename T, long tam>
int Vector<T, tam>::getNumElementos() const {
    return nelem;
}

template <typename T, long tam>
int Vector<T, tam>::getCapacidad() const {
    return tam;
}

#endif
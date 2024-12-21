#ifndef VECTOR_H
#define VECTOR_H

#include "ExcepcionVectorRango.h"

template <typename T, long tam = 10>
class Vector {
private:
    T array[tam];
    int nelem; 

public:
    Vector();
    ~Vector();

    bool addElement(const T& elem);
    bool buscar(const T& elem) const;
    bool eliminar(const T& elem);
    T operator[](int n) const;
    bool operator==(const Vector<T, tam>& other) const;

    // Getters
    int getNumElementos() const;
    int getCapacidad() const;
};

#include "Vector.cpp"

#endif
#ifndef EXCEPCION_VECTOR_RANGO_H
#define EXCEPCION_VECTOR_RANGO_H

#include <exception>
#include <string>

class ExcepcionVectorRango : public std::exception {
private:
    int pos;
    int numElem;
    std::string msg;

public:
    ExcepcionVectorRango(int p, int n);
    ~ExcepcionVectorRango() _NOEXCEPT override = default;

    const char* what() const _NOEXCEPT override;
    int getPos() const;
    int getNumElem() const;
};

#include "ExcepcionVectorRango.cpp"

#endif
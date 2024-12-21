#include "ExcepcionVectorRango.h"

ExcepcionVectorRango::ExcepcionVectorRango(int p, int n)
    : pos(p), numElem(n), msg("Acceso fuera de rango.") {}

const char* ExcepcionVectorRango::what() const _NOEXCEPT {
    return msg.c_str();
}

int ExcepcionVectorRango::getPos() const {
    return pos;
}

int ExcepcionVectorRango::getNumElem() const {
    return numElem;
}
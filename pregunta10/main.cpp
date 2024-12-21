#include <iostream>
#include "include/Vector.h"
#include "include/ExcepcionVectorRango.h"

int main() {
    try {
        Vector<int, 5> v;

        v.addElement(10);
        v.addElement(20);
        v.addElement(30);

        // Probar buscar
        std::cout << "¿Contiene 20? " << (v.buscar(20) ? "Sí" : "No") << std::endl;

        // Probar eliminar
        v.eliminar(20);
        std::cout << "¿Contiene 20 después de eliminar? " << (v.buscar(20) ? "Sí" : "No") << std::endl;

        // Probar acceso con operador []
        std::cout << "Elemento en posición 0: " << v[0] << std::endl;

        // Probar excepción por índice fuera de rango
        std::cout << "Elemento en posición 10: " << v[10] << std::endl;

    } catch (const ExcepcionVectorRango& ex) {
        std::cerr << ex.what() << " Posición: " << ex.getPos()
                  << ", Número de elementos: " << ex.getNumElem() << std::endl;
    }

    return 0;
}
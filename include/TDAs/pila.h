#ifndef PILA_H

#include <iostream>

/* Para implementar la pila utilizaremos listas enlazadas simples*/


// Clase pila 
template <typename T>
class Pila {
    
    private:
        // Estructura de los nodos pila
        struct Nodo {
            T dato;
            Nodo* siguiente;

            Nodo(T valor): dato(valor), siguiente(nullptr) {}
        };

        // Nodo al tope de una pila
        Nodo* tope; 

    public:
        // Inicio / Destruccion
        Pila();
        ~Pila();
        
        // Operaciones 
        void push(const T& elemento);
        T pop();
        T top() const;
        bool estaVacia() const;
};

#endif // PILA_H


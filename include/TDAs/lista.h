#ifndef LISTA_H

#include <iostream>

// Clase lista 
template <typename T>
class Lista {
    
    private:
        // Estructura de los nodos lista
        struct Nodo {
            T dato;
            Nodo* siguiente;
            Nodo* anterior;

            Nodo(T valor): dato(valor), siguiente(nullptr), anterior(nullptr) {}
        };

        // Nodo al tope de una pila
        Nodo* head; 

    public:
        // Construir / Destruir
        Lista();
        ~Lista();

        // Operaciones
        Nodo* getHead() const;
        void pushFront(T valor);
        void pushBack(T valor); 
        Nodo* search(const T& valor);
        void popCurrent(const T& valor);
};

#endif // LISTA_H
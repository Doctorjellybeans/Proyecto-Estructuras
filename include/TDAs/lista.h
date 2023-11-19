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

// Constructor
template <typename T>
Lista<T>::Lista() : head(nullptr) {}

// Destructor
template <typename T>
Lista<T>::~Lista() {
    Nodo* actual = head;
    while (actual) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Obtener primer nodo (cabeza) de la lista
template <typename T>
typename Lista<T>::Nodo* Lista<T>::getHead() const {
    return head;
}

// Agregar elementos al inicio de la lista
template <typename T>
void Lista<T>::pushFront(T valor) {
    Nodo* nuevoNodo = new Nodo(valor);
    if (!head) {
        head = nuevoNodo;
    } else {
        nuevoNodo->siguiente = head;
        head->anterior = nuevoNodo;
        head = nuevoNodo;
    }
}

// Busca un elemento en la lista / devuelve el nodo
template <typename T>
typename Lista<T>::Nodo* Lista<T>::search(const T& valor) {
    Nodo* actual = head;
    while (actual) {
        // Eureka, encontramos el nodo
        if (actual->dato == valor) {
            return actual;
        }
        actual = actual->siguiente;
    }
    // No se encontro
    return nullptr;
}

// Elimina un nodo con un valor especifico de la lista 
template <typename T>
void Lista<T>::popCurrent(const T& valor) {
    Nodo* nodoEliminar = search(valor);
    if (nodoEliminar) {
        if (nodoEliminar->anterior) {
            nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
        } else {
            // Es el primer nodo
            head = nodoEliminar->siguiente;
        }

        if (nodoEliminar->siguiente) {
            nodoEliminar->siguiente->anterior = nodoEliminar->anterior;
        }

        delete nodoEliminar;
    }
}


#endif // LISTA_H
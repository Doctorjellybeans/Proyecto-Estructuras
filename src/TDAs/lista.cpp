#include "TDAs/lista.h"

// Construir lista
template <typename T>
Lista<T>::Lista() : head(nullptr) {}

// Destruccion masiva de la pobre lista
template <typename T>
Lista<T>::~Lista() {
    Nodo* actual = head;
    while (actual) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
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

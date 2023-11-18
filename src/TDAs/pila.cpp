#include "TDAs/pila.h"

/*comentario aparte, C++ es muy confuso*/

// Inicializar pila
template <typename T>
Pila<T>::Pila() : tope(nullptr) {}

// Destruir pila
template <typename T>
Pila<T>::~Pila() {
    while (!estaVacia()){
        pop();
    }
}

// Apilar elemntos a la pila
template <typename T>
void Pila<T>::push(const T& elemento) {
    Nodo* nuevoNodo = new Nodo(elemento);
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
}

// Desapilar elementos de la pila cuchau
template <typename T>
T Pila<T>::pop() {
    if (estaVacia()){
        throw std::out_of_range("La pila esta vacia");
    }

    Nodo* nodoEliminar = tope;
    tope = tope->siguiente;
    T valor = nodoEliminar->dato;
    delete nodoEliminar;

    return valor;
} 

// Comprobar si la pila esta vacia
template <typename T>
bool Pila<T>::estaVacia() const {
    return tope == nullptr;
}

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


#endif // PILA_H


#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stdexcept> 

/* Para implementar la pila utilizaremos listas enlazadas simples*/

// Clase nodo de una pila
template <typename T>
class NodoPila {
    public:
        int clave;
        T valor;
        NodoPila* siguiente;

        NodoPila(int k, T val) : clave(k), valor(val), siguiente(nullptr) {}
};

// Clase pila
template <typename T>
class Pila {
    private:
        NodoPila<T>* tope;

    public:
        Pila() : tope(nullptr) {}

        ~Pila() {
            while (!estaVacia()) {
                desapilar();
            }
        }

        void apilar(int clave, T val) {
            NodoPila<T>* nuevoNodo = new NodoPila<T>(clave, val);
            if (tope == nullptr) {
                tope = nuevoNodo;
            } else {
                nuevoNodo->siguiente = tope;
                tope = nuevoNodo;
            }
        }

        T desapilar() {
            if (estaVacia()) {
                throw std::out_of_range("La pila esta vacia lol");
            }

            NodoPila<T>* temp = tope;
            T objetoDesapilado = temp->valor;
            tope = tope->siguiente;
            delete temp;

            return objetoDesapilado;
        }

        T obtenerTope() const {
            if (!estaVacia()) {
                return tope->valor;
            } else {
                std::cerr << "La pila está vacía." << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        bool estaVacia() const {
            return tope == nullptr;
        }
};


#endif // PILA_H


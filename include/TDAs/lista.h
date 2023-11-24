#ifndef LISTA_H
#define LISTA_H

#include <iostream>

// Clase Nodo de una lista
template <typename T>
class Nodo {
    public:
        int clave;
        T valor;
        Nodo* siguiente;
        Nodo* anterior;

        Nodo(int k, T val) : clave(k), valor(val), siguiente(nullptr), anterior(nullptr) {}
};

// Clase lista
template <typename T>
class Lista {
    private:
        int tamanio;
        Nodo<T>* cabeza;
        Nodo<T>* cola;

    public:
        Lista() : tamanio(0), cabeza(nullptr), cola(nullptr) {}

        ~Lista() {
            while (cabeza != nullptr) {
                Nodo<T>* temp = cabeza;
                cabeza = cabeza->siguiente;
                delete temp;
            }
        }

        int obtenerTamanio() const {
            return tamanio;
        }

        void insertarAtras(int clave, T val) {
            Nodo<T>* nuevoNodo = new Nodo<T>(clave, val);
            if (cabeza == nullptr) {
                cabeza = nuevoNodo;
                cola = nuevoNodo;
            } else {
                nuevoNodo->anterior = cola;
                cola->siguiente = nuevoNodo;
                cola = nuevoNodo;
            }
            tamanio++;
        }

        void insertarFrente(int clave, T val) {
            Nodo<T>* nuevoNodo = new Nodo<T>(clave, val);
            if (cabeza == nullptr) {
                cabeza = nuevoNodo;
                cola = nuevoNodo;
            } else {
                nuevoNodo->siguiente = cabeza;
                cabeza->anterior = nuevoNodo;
                cabeza = nuevoNodo;
            }
            tamanio++;
        }

        void eliminarAtras() {
            if (cola != nullptr) {
                Nodo<T>* temp = cola;
                cola = cola->anterior;
                if (cola != nullptr) {
                    cola->siguiente = nullptr;
                } else {
                    cabeza = nullptr;
                }
                delete temp;
                tamanio--;
            }
        }

        void eliminarFrente() {
            if (cabeza != nullptr) {
                Nodo<T>* temp = cabeza;
                cabeza = cabeza->siguiente;
                if (cabeza != nullptr) {
                    cabeza->anterior = nullptr;
                } else {
                    cola = nullptr;
                }
                delete temp;
                tamanio--;
            }
        }

        void eliminarActual(int clave) {
            Nodo<T>* actual = buscar(clave);
            if (actual != nullptr) {
                if (actual->anterior != nullptr) {
                    actual->anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }

                if (actual->siguiente != nullptr) {
                    actual->siguiente->anterior = actual->anterior;
                } else {
                    cola = actual->anterior;
                }

                delete actual;
                tamanio--;
            }
        }

        Nodo<T>* buscar(int clave) {
            Nodo<T>* actual = cabeza;
            while (actual != nullptr) {
                if (actual->clave == clave) {
                    return actual;
                }
                actual = actual->siguiente;
            }
            return nullptr; // No se encontró la clave
        }
};

#endif // LISTA_H

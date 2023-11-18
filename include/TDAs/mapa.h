#ifndef MAPA_H

#include <iostream>

// Inclusion de lista para resolver colisiones con listas enlazadas
#include "lista.h" 

template <typename K, typename V>
class Mapa {
    private:
        static const int TAMANIO_INICIAL = 10;
        static const double FACTOR_DE_CARGA_MAXIMO;

        Lista<std::pair<K,V>>* tabla; // Arreglo de Listas 
        int capacidad;                // Tamanio de la tabla
        int elementos;                // Elementos presentes en la tabla

        /* La funcion hash quedara sujeta a cambios */
        int funcionHash(const K& clave) const;

        void redimensionarTabla(int nuevoTamanio);
    
    public:
        // Construir / Destruir 
        Mapa();
        ~Mapa();

        // Operaciones de la tablisha
        void insertar(const K& clave, const V& valor);
        typename Lista<std::pair<K, V>>::Nodo* buscar(const K& clave) const;
        void eliminar(const K& clave); 
};


#endif // MAPA_H
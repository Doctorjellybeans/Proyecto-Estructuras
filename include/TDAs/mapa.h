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

// Inicializacion de la constante factor de carga maximo
template <typename K, typename V>
const double Mapa<K, V>::FACTOR_DE_CARGA_MAXIMO = 0.7;

// Constructor de la clase Mapa
template <typename K, typename V>
Mapa<K, V>::Mapa() : capacidad(TAMANIO_INICIAL), elementos(0) {
    tabla = new Lista<std::pair<K, V>>[capacidad];  // Falta especificar el tipo de datos dentro de Lista
}

/*En cuanto a la Funcion hash, prefiero que la manejes tu mati
  en caso de que encuentres mas apropiado otra implementacion 
  
    template <typename K, typename V>
    int Mapa<K, V>::hashFunc(const K& clave) const {
        return std::hash<K>{}(clave) % capacidad;
    }

*/

// Redimensionar tabla hash
template <typename K, typename V>
void Mapa<K, V>::redimensionarTabla(int nuevoTamanio) {
    Lista<std::pair<K, V>>* nuevaTabla = new Lista<std::pair<K, V>>[nuevoTamanio];

    for (int i = 0; i < capacidad; i++) {
        typename Lista<std::pair<K, V>>::Nodo* actual = tabla[i].getHead();
        while (actual) {
            std::pair<K, V> elemento = actual->dato;
            int nuevoIndice = funcionHash(elemento.first) % nuevoTamanio;
            nuevaTabla[nuevoIndice].pushBack(elemento);
            actual = actual->siguiente;
        }
    }

    // Actualizar capacidad y tabla
    capacidad = nuevoTamanio;
    delete[] tabla;
    tabla = nuevaTabla;
}

// Insertar elementos a la tabla hash
template <typename K, typename V>
void Mapa<K, V>::insertar(const K& clave, const V& valor) {
    // Insertar par / comprobar factor de carga
    if ((double)elementos / capacidad > FACTOR_DE_CARGA_MAXIMO) {
        int nuevoTamanio = capacidad * 2;
        redimensionarTabla(nuevoTamanio);
    }

    int indice = funcionHash(clave);
    std::pair<K, V> nuevoPar(clave, valor);
    tabla[indice].pushBack(nuevoPar);
    elementos++;
}
// Buscar elementos en la tabla
template <typename K, typename V>
typename Lista<std::pair<K, V>>::Nodo* Mapa<K, V>::buscar(const K& clave) const {
    int indice = funcionHash(clave);
    return tabla[indice].search(std::make_pair(clave, V()));
}

  

#endif // MAPA_H
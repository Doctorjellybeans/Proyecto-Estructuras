#ifndef MAPA_H

#include <iostream>

// Inclusion de lista para resolver colisiones con listas enlazadas
#include "lista.h" 

template <typename T>
class Mapa {
    private:
        static const int TAMANO_INICIAL = 10;
        static const double FACTOR_DE_CARGA_MAXIMO;

        Lista<std::pair<K,V>>* tabla;
        int capacidad;
        int elementos;

        int funcionHash(const K& clave) const;

        void redimensionarTabla(int nuevoTamanio);
    
    public:
        Mapa();
        ~Mapa();

        void insertar(const K& clave, const V& valor);
        typename Lista<std::pair<K, V>>::Nodo* buscar(const K& clave) const;
        void eliminar(const K& clave); 
};


#endif // MAPA_H
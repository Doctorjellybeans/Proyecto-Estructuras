#ifndef MAPA_H

#include <iostream>
#include "lista.h" 

// Clase nodo mapa
template <typename K, typename V>
class NodoMapa {
    public:
        K clave;
        V valor;

        NodoMapa(const K& k, const V& val) : clave(k), valor(val) {}
};

// Clase mapa
template <typename K, typename V>
class Mapa {
    private:
        int capacidad;
        int elementos;
        std::list<NodoMapa<K, V>>* tabla;

        static const double FACTOR_DE_CARGA;

        int funcionHash(const K& clave) const {
            // Función hash simple para convertir la clave a un índice en la tabla
            // (puedes mejorarla dependiendo de tus necesidades)
            return std::hash<K>{}(clave) % capacidad;
        }

        void redimensionarTabla() {
            // Doble la capacidad y vuelve a insertar todos los elementos
            int nuevaCapacidad = capacidad * 2;
            std::list<NodoMapa<K, V>>* nuevaTabla = new std::list<NodoMapa<K, V>>[nuevaCapacidad];

            for (int i = 0; i < capacidad; ++i) {
                for (const auto& nodo : tabla[i]) {
                    int indice = funcionHash(nodo.clave);
                    nuevaTabla[indice].emplace_back(nodo);
                }
            }

            delete[] tabla;
            tabla = nuevaTabla;
            capacidad = nuevaCapacidad;
        }

    public:
        Mapa(int capacidadInicial = 10) : capacidad(capacidadInicial), elementos(0) {
            tabla = new std::list<NodoMapa<K, V>>[capacidadInicial];
        }

        ~Mapa() {
            delete[] tabla;
        }

        void insertar(const K& clave, const V& valor) {
            int indice = funcionHash(clave);

            // Busca si la clave ya existe en la lista y, si es así, actualiza el valor
            for (auto& nodo : tabla[indice]) {
                if (nodo.clave == clave) {
                    nodo.valor = valor;
                    return;
                }
            }

            // Si la clave no existe, agrega un nuevo nodo a la lista
            tabla[indice].emplace_back(clave, valor);
            elementos++;

            // Verifica si se debe redimensionar la tabla
            if (static_cast<double>(elementos) / capacidad > FACTOR_DE_CARGA) {
                redimensionarTabla();
            }
        }

        bool buscar(const K& clave, V& valor) const {
            int indice = funcionHash(clave);

            // Busca la clave en la lista
            for (const auto& nodo : tabla[indice]) {
                if (nodo.clave == clave) {
                    valor = nodo.valor;
                    return true;
                }
            }

            return false;
        }

        void eliminar(const K& clave) {
            int indice = funcionHash(clave);

            // Busca la clave en la lista y la elimina
            auto it = std::remove_if(tabla[indice].begin(), tabla[indice].end(),
                                    [&clave](const NodoMapa<K, V>& nodo) {
                                        return nodo.clave == clave;
                                    });

            if (it != tabla[indice].end()) {
                tabla[indice].erase(it, tabla[indice].end());
                elementos--;
            }
        }

        void imprimir() const {
            for (int i = 0; i < capacidad; ++i) {
                for (const auto& nodo : tabla[i]) {
                    std::cout << "Clave: " << nodo.clave << ", Valor: " << nodo.valor << std::endl;
                }
            }
        }
};

template <typename K, typename V>
const double Mapa<K, V>::FACTOR_DE_CARGA = 0.75;

  

#endif // MAPA_H
#ifndef SALUD_H
#define SALUD_H

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "TDAs/pila.h"
#include "TDA-OH/cartas.h"
#include "TDAs/queue.h"
#include "TDAs/lista.h"
#include "TDA-Oh/enum.h"

class BarraSalud {
    private:
        int puntos;

        Pila<int> pilaSalud;
        Queue<int> colaSalud;
        Lista<int> listaSalud;

        TipoTDA tipoActual;

    public:
        BarraSalud(int puntosIniciales, TipoTDA tipoTdaInicial) : puntos(puntosIniciales), tipoActual(tipoTdaInicial) {
            
            for (int i = 0; i < puntosIniciales; i++) {
                pilaSalud.apilar(i,1);
                colaSalud.push(i);
                listaSalud.insertarAtras(i,1);
            }
        }

        TipoTDA buscarTipoTDAInversa(OperacionTDA operacion) {
            std::unordered_map<OperacionTDA, TipoTDA> mapaOperacionTipo = {
                {OperacionTDA::APILAR, TipoTDA::PILA},
                {OperacionTDA::DESAPILAR, TipoTDA::PILA},
                {OperacionTDA::ENCOLAR, TipoTDA::COLA},
                {OperacionTDA::DESENCOLAR, TipoTDA::COLA},
                {OperacionTDA::INSERTAR, TipoTDA::LISTA},  
                {OperacionTDA::ELIMINAR, TipoTDA::LISTA},
                {OperacionTDA::CAMBIARTDA, TipoTDA::ESPECIAL}
            };

            
            // Busca la operación inversa en el mapa
            auto iterador = mapaOperacionTipo.find(operacion);

            // Si se encuentra, devuelve el tipo asociado; de lo contrario, devuelve un valor predeterminado
            if (iterador != mapaOperacionTipo.end()) {
                return iterador->second;
            } else {
                return TipoTDA::ESPECIAL; 
            }
        }

        bool jugadaEsValida(TipoTDA tdaHP, OperacionTDA operacionCarta) {
            TipoTDA comparacion = buscarTipoTDAInversa(operacionCarta);

            return comparacion == tdaHP;
        }

        void cambiarSiguiente() {
            switch (tipoActual) {
                case TipoTDA::PILA:
                    tipoActual = TipoTDA::COLA;
                    break;
                case TipoTDA::COLA:
                    tipoActual = TipoTDA::LISTA;
                    break;
                case TipoTDA::LISTA:
                    tipoActual = TipoTDA::PILA;
                    break;
            }
        }

        void recibirDanio(int cantidadDanio, OperacionTDA operacionCarta) {
            if (jugadaEsValida(tipoActual, operacionCarta)){
                for (int i = 0; i < cantidadDanio; i++) {
                    pilaSalud.desapilar();
                    colaSalud.pop();
                    listaSalud.eliminarFrente();
                }

                puntos -= cantidadDanio;
                if (puntos < 0) {
                    puntos = 0;
                }
            }   
        }

        void curar(int cantidadCuracion, OperacionTDA operacionCarta) {
            if (jugadaEsValida(tipoActual, operacionCarta)) {
                int tope = puntos + cantidadCuracion;
                for (int i = puntos; i < tope; i++) {
                    pilaSalud.apilar(i,1);
                    colaSalud.push(i);
                    listaSalud.insertarAtras(i,1);
                }
                puntos += cantidadCuracion;
                if (puntos > 20) {
                    puntos = 20;
                }
            }
        }

        void cambiarTDA() {

        }

        int obtenerPuntos() {
            return puntos;
        }

        TipoTDA obtenerTDA() {
            return tipoActual;
        }

};

#endif // SALUD_H
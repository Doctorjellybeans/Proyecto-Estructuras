#ifndef SALUD_H
#define SALUD_H

#include <iostream>
#include "TDAs/pila.h"
#include "TDA-OH/cartas.h"
#include "TDAs/queue.h"
#include "TDAs/lista.h"

enum class TipoTDA {
    PILA,
    COLA,
    LISTA
};

class Salud {
    public:

    Salud() : tipoActual(TipoTDA::PILA) {}

    ~Salud() {}

    void obtenerTipoActual() const {
        return tipoActual;
    }

    int esValido(Carta carta) {
        TipoOperacion operacion = carta.obtenerOperacion();
        TipoCarta tipoCarta = carta.obtenerTipo();

        if (tipoActual == TipoTDA::PILA) {
            
            switch (TipoCarta) {
                case TipoCarta::DANIO:
                    if (operacion == TipoOperacion::Desapilar) {
                        return 1;
                    }
                    return -1;

                case TipoCarta::VIDA:
                    if (operacion == TipoOperacion::Apilar) {
                        return 2;
                    }
                    return -1;

                default:
                    break;
            }

        } else if (tipoActual == TipoTDA::COLA) {
            
            switch (TipoCarta) {
                case TipoCarta::DANIO:
                    if (operacion == TipoOperacion::Desencolar) {
                        return 1;
                    }
                    return -1;

                case TipoCarta::VIDA:
                    if (operacion == TipoOperacion::Encolar) {
                        return 2;
                    }
                    return -1;

                default:
                    break;
            }

        } else if (tipoActual == TipoTDA::LISTA) {
            switch (TipoCarta) {
                case TipoCarta::DANIO:
                    if (operacion == TipoOperacion::EliminarActual) {
                        return 1;
                    } 
                    return -1;

                case TipoCarta::VIDA:
                    if (operacion == TipoOperacion::InsertarActual) {
                        return 2;
                    }
                    return -1;

                default:
                    break;
            }
        } else if (tipoCarta == TipoCarta::EFECTO) {
            return 3
        }
    }

    void causarDanio(int puntajeCarta) {
        for (int i = 0; i < puntajeCarta; i++) {
            pilaSalud.desapilar();
            colaSalud.pop();
            listaSalud.eliminarAtras();
        }
    }

    void curarVida(int puntajeCarta) {
        for (int i = 0; i < puntajeCarta; i++) {
            pilaSalud.desapilar();
            colaSalud.pop();
            listaSalud.eliminarAtras();
        }
    }

    void cambiarSiguiente() {
        switch (tipoActual) {
            case TipoTDA::Pila:
                tipoActual = TipoTDA::Cola;
                break;
            case TipoTDA::Cola:
                tipoActual = TipoTDA::Lista;
                break;
            case TipoTDA::Lista:
                tipoActual = TipoTDA::Pila;
                break;
        }
    }


    void operacion(Carta carta) {
        int puntajeCarta = carta.obtenerPuntaje();
        int tipoCarta = esValido(carta);

        if (tipoCarta == -1) { // No se puede operar
            
        } else { // Se puede operar
            
            switch (tipoCarta) {
                case 1: // DANIO
                    causarDanio();
                    break;
                case 2: // SALUD
                    curarVida();
                    break;

                case 3: // EFECTO
                    cambiarSiguiente();
                    break;

                default:
                    break;
            }
        }
    }

    private:
        Pila<int> pilaSalud;
        Queue<int> colaSalud;
        Lista<int> listaSalud;

        TipoTDA tipoActual;

};

#endif // SALUD_H
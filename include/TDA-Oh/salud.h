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

    void cambiarTipoTDA(TipoTDA nuevoTipo) {
        tipoActual = nuevoTipo;
    }

    bool esValido(Carta carta) {
        TipoOperacion operacion = carta.obtenerOperacion();
        TipoCarta tipoCarta = carta.obtenerTipo();

        switch (tipoCarta) {
            case TipoCarta::VIDA:
                if (operacion == TipoOperacion::Apilar) {
                    return true;
                } else if {
                    
                }
            case TipoCarta::DANIO:
                // algo
            case TipoCarta::EFECTO
                // algo
            default
                return false;
        }
    }

    bool esValido(Carta carta) {

    }

    void operacion(Carta carta) {
        switch (tipoActual) {
            case TipoTDA::PILA:

        }
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
    }

    private:
        Pila<int> pilaSalud;
        Queue<int> colaSalud;
        Lista<int> listaSalud;

        TipoTDA tipoActual;

};

#endif // SALUD_H
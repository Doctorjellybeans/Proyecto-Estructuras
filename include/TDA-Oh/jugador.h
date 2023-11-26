#ifndef JUGADOR_H
#define JUGADOR_H

#include "TDAs/lista.h"
#include "TDA-Oh/cartas.h"
#include "TDA-Oh/salud.h"
#include "TDA-Oh/mazo.h"

#include <iostream>

class Jugador {
    private:
        BarraSalud barraSalud;
        Lista<Carta*> mano;

    public:
        Jugador(int puntosSaludInicial, TipoTDA tipoTdaInicial) : barraSalud(puntosSaludInicial, tipoTdaInicial)  {}

        void recibirDanio(int cantidadDanio, OperacionTDA operacionCarta) {
            barraSalud.recibirDanio(cantidadDanio, operacionCarta);
        }

        void curar(int cantidadDanio, OperacionTDA operacionCarta) {
            barraSalud.recibirDanio(cantidadDanio, operacionCarta);
        }

        void agregarCartaAMano(Mazo& mazo) {
            Carta* cartaTope = mazo.sacarCarta();
            mano.insertarFrente(0, cartaTope);
        }

        void jugarCarta() {}

        int obtenerSalud() const {
            return 0;
        }

        TipoTDA obtenerTipoTDA() {
            return barraSalud.obtenerTDA();
        }

        
};


#endif // JUGADOR_H
#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include "mano.h"
#include "salud.h"
#include "mazo.h"

class Jugador {
    private:
        Mazo& mazo;
        Mano mano;
        Salud& salud;
        std::string nombreJugador;
    
    public:
        Jugador(Mazo& mazo, const std::string& nombre, Salud& salud) : mazo(mazo), nombreJugador(nombre), salud(salud) {
            mazo.rellenarMazo();
            mano.crearMano(mazo);
            salud.crearSalud(20);
        }

        // ~Jugador();

        void robarCarta() {
            mano.agregarCarta(mazo);   
        }

        void jugarCarta() {
            Carta cartaJugada = obtenerCartaJugada();

            if (salud.validarJugada(cartaJugada)) {
                // Si funca, jugar carta
            } else {
                // No funca, no jugar
            }
        }

        Nodo<Carta>* obtenerCartaJugada(int posicion) {
            return mano.buscarCarta(posicion);
        }

        bool pasarTurno();
};  


#endif // JUGADOR_H
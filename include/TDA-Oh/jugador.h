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
        Salud salud;
        std::string nombreJugador;
    
    public:
        Jugador(Mazo& mazo, const std::string& nombre) : mazo(mazo), nombreJugador(nombre) {
            mazo.rellenarMazo();
            mano.crearMano(mazo);
        }

        // ~Jugador();

        // Salud& obtenerSalud;

        void robarCarta() {
            mano.agregarCarta(mazo);   
        }

        Nodo<Carta>* jugarCarta(int posicion) {
            return mano.buscarCarta(posicion);
        }

        bool pasarTurno();
};  


#endif // JUGADOR_H
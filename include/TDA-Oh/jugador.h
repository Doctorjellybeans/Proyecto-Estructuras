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
            mano.crearMano(mazo);
            salud.crearSalud(20,TipoTDA::PILA);
        }

        void robarCarta() {
            mano.agregarCarta(mazo);   
        }

        void jugarCarta(int posicion) {
            Carta cartaJugada = obtenerCartaJugada(posicion);
        }

        void manoJugador(){
            mano.mostrarMano();
        }

        Carta obtenerCartaJugada(int posicion) {
            Nodo<Carta>* nodo = mano.buscarCarta(posicion);
            Carta carta = nodo->valor;
            return carta;
        }

        bool pasarTurno();
};  


#endif // JUGADOR_H
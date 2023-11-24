#ifndef MANO_H
#define MANO_H


#include "TDAs/lista.h"
#include "TDA-Oh/mazo.h"
#include "TDA-Oh/cartas.h"

class Mano {
    public:
        
        Lista<Carta>* crearMano(Mazo& mazo) {
            for (int i = 0; i < 3; i++) {
                Carta carta = mazo.sacarCarta();
                mano.insertarFrente(i,carta);
            }

            return &mano;
        }

        void agregarCarta(Mazo& mazo) {
            mano.insertarFrente(mano.obtenerTamanio(),mazo.sacarCarta());
        }

        void mostrarMano() const;
        
        void descartarCarta(int posicion) {
            mano.eliminarActual(posicion);
        }

        Nodo<Carta>* buscarCarta(int posicion) {
            Nodo<Carta>* nodoCarta = mano.buscar(posicion);
            return nodoCarta;
        }

        bool estaVacia() {
            if (mano.buscar(0)) {
                return true;
            }
            return false;
        }

    private:
        Lista<Carta> mano;
};


#endif // MANO_H
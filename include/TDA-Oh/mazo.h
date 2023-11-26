#ifndef MAZO_H
#define MAZO_H

#include "TDAs/pila.h"
#include "TDA-Oh/cartas.h"

class Mazo {
    private:
        Pila<Carta*> mazo;
    
    public:
        void rellenarMazo() {}

        Carta* sacarCarta() {
            if (!mazo.estaVacia()) {
                Carta* carta = mazo.desapilar();
                return carta;
            }
        }

        bool estaVacio() {
            return mazo.estaVacia();
        }

};

#endif // MAZO_H
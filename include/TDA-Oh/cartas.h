#ifndef CARTAS_H
#define CARTAS_H

#include <iostream>
#include "TDA-Oh/jugador.h"
#include "TDA-Oh/enum.h"


class Carta {
    private:
        OperacionTDA operacion;
    
    public:
        Carta(OperacionTDA operacionCarta) : operacion(operacionCarta) {}

        virtual void aplicarEfecto(Jugador& objetivo) const = 0;
        
        OperacionTDA obtenerOperacionTDA() const {
            return operacion;
        }

        virtual ~Carta() {}
};

class CartaDanio : public Carta {
    private:
        int cantidadDanio;
        
    public:
        CartaDanio(int danio, OperacionTDA operacionCarta) : Carta(operacionCarta), cantidadDanio(danio) {}

        void aplicarEfecto(Jugador& objetivo) const override {
            objetivo.recibirDanio(cantidadDanio, obtenerOperacionTDA());
        }
};

#endif // CARTAS_H
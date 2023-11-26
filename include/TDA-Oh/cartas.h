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
        CartaDanio(OperacionTDA operacionCarta, int danio) : Carta(operacionCarta), cantidadDanio(danio) {}

        void aplicarEfecto(Jugador& objetivo) const override {
            objetivo.recibirDanio(cantidadDanio, obtenerOperacionTDA());
        }
};

class CartaVida : public Carta {
    private:
        int cantidadCura;
    
    public:
        CartaVida(OperacionTDA operacionCarta, int cura) : Carta(operacionCarta), cantidadCura(cura) {}

        void aplicarEfecto(Jugador& objetivo) const override {
            objetivo.curar(cantidadCura, obtenerOperacionTDA());
        } 
};

class CartaEfecto : public Carta {
    public:
        CartaEfecto(OperacionTDA operacionCarta) : Carta(operacionCarta) {}

        void aplicarEfecto(Jugador& objetivo) const override {
            objetivo.cambiarTDA();
        }
};

#endif // CARTAS_H
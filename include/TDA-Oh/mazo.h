#ifndef MAZO_H
#define MAZO_H

#include "TDAs/pila.h"
#include "TDA-Oh/cartas.h"
#include <random>

class Mazo {
    public:
        void rellenarMazo() {
            for (int i = 0; i < 56 ; i++) {
                int opcion = numeroAleatorio(3);

                if (opcion == 1) {
                    Carta cartaDanio(TipoCarta::DANIO, operacionAleatoria(TipoCarta::DANIO), numeroAleatorio(3));
                    mazo.apilar(i,cartaDanio);
                } else if (opcion == 2) {
                    Carta cartaVida(TipoCarta::VIDA, operacionAleatoria(TipoCarta::VIDA), numeroAleatorio(3));
                    mazo.apilar(i,cartaVida);
                } else if (opcion == 3) {
                    Carta cartaEfecto(TipoCarta::EFECTO, operacionAleatoria(TipoCarta::EFECTO), numeroAleatorio(3));
                    mazo.apilar(i,cartaEfecto);
                }
            }
        }

        Carta sacarCarta() {
            Carta carta = mazo.desapilar();
            
            if (mazo.estaVacia()) {
                rellenarMazo();
            }

            return carta;
        }

        bool estaVacio() {
            if (mazo.estaVacia()) {
                return true;
            }
            return false;
        }

    private:
        Pila<Carta> mazo;

        int numeroAleatorio(int num) const {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribucion(1, num);
            
            return distribucion(gen);
        }

        TipoOperacion operacionAleatoria(TipoCarta tipo) const {
            TipoOperacion operacion;

            if (tipo == TipoCarta::DANIO) {
                static const TipoOperacion operacionesDanio[] = {TipoOperacion::Desapilar, TipoOperacion::Desencolar, TipoOperacion::EliminarActual};
                operacion = operacionesDanio[numeroAleatorio(3)];
            } else if (tipo == TipoCarta::VIDA) {
                static const TipoOperacion operacionesVida[] = {TipoOperacion::Apilar, TipoOperacion::Encolar, TipoOperacion::InsertarActual};
                operacion = operacionesVida[numeroAleatorio(3)];
            } else if (tipo == TipoCarta::EFECTO) {
                static const TipoOperacion operacionesEspeciales[] = {TipoOperacion::CambiarTda};
                operacion = operacionesEspeciales[numeroAleatorio(1)];
            }

            return operacion;
        }
};

#endif // MAZO_H
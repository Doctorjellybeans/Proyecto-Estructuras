#ifndef MAZO_H
#define MAZO_H

#include "TDAs/pila.h"
#include "TDA-Oh/cartas.h"
#include "TDA-Oh/enum.h"
#include <random>

class Mazo {
    private:
        Pila<Carta*> mazo;

        int numeroAleatorio(int num) const {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribucion(1, num);
            
            return distribucion(gen);
        }

        OperacionTDA operacionAleatoria(TipoTDA tipo) const {
            OperacionTDA operacion;

            switch (tipo) {
                case TipoTDA::PILA:
                    static const OperacionTDA operacionesPila[] = {OperacionTDA::DESAPILAR, OperacionTDA::APILAR};
                    operacion = operacionesPila[numeroAleatorio(2)];
                    break;
                case TipoTDA::COLA:
                    static const OperacionTDA operacionesCola[] = {OperacionTDA::ENCOLAR, OperacionTDA::DESENCOLAR};
                    operacion = operacionesCola[numeroAleatorio(2)];
                    break;
                case TipoTDA::LISTA:
                    static const OperacionTDA operacionesLista[] = {OperacionTDA::INSERTAR, OperacionTDA::ELIMINAR};
                    operacion = operacionesLista[numeroAleatorio(2)];
                    break;
                case TipoTDA::ESPECIAL:
                    static const OperacionTDA operacionesEspeciales[] = {OperacionTDA::CAMBIARTDA};
                    operacion = operacionesEspeciales[0];

            }

            return operacion;
        }
    
    public:
        void rellenarMazo() {
            for (int i = 0; i < 56 ; i++) {
                int opcion = numeroAleatorio(3);

                if        (opcion == 1) { // CARTA DANIO
                    // faltan mas tdas
                    CartaDanio* cartaDanio = new CartaDanio(operacionAleatoria(TipoTDA::PILA) ,numeroAleatorio(3));
                    mazo.apilar(i,cartaDanio);

                } else if (opcion == 2) { // CARTA VIDA
                    // faltan mas tdas
                    CartaVida* cartaVida = new CartaVida(operacionAleatoria(TipoTDA::PILA) ,numeroAleatorio(3));
                    mazo.apilar(i,cartaVida);
                
                } else if (opcion == 3) { // CARTA ESPECIAL
                    CartaEfecto* cartaEfecto = new CartaEfecto(OperacionTDA::CAMBIARTDA);
                    mazo.apilar(i,cartaEfecto);
                }
            }
        }

        Carta* sacarCarta() {
            if (!mazo.estaVacia()) {
                Carta* carta = mazo.desapilar();
                return carta;
            } else {
                rellenarMazo();
            }
        }

        bool estaVacio() {
            return mazo.estaVacia();
        }

};

#endif // MAZO_H
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

        int largoMano(){
            return mano.obtenerTamanio();
        }

        void mostrarMano() {
            for (int i = 0; i < mano.obtenerTamanio() + 1; i++) {
                Nodo<Carta>* nodo = buscarCarta(i);
                Carta carta = nodo->valor;
                
                TipoCarta tipo = carta.obtenerTipo();
                if (tipo == TipoCarta::DANIO) std:: cout << "DANIO ";
                if (tipo == TipoCarta::VIDA) std:: cout << "VIDA ";
                if (tipo == TipoCarta::EFECTO) std:: cout << "EFECTO ";
                
                TipoOperacion op = carta.obtenerOperacion();
                if (op == TipoOperacion::Apilar) std:: cout <<"Apilar ";
                if (op == TipoOperacion::Desapilar) std:: cout <<"Desapilar ";
                if (op == TipoOperacion::Encolar) std:: cout <<"Encolar ";
                if (op == TipoOperacion::Desencolar) std:: cout <<"Desencolar ";
                if (op == TipoOperacion::InsertarActual) std:: cout <<"InsertarActual ";
                if (op == TipoOperacion::EliminarActual) std:: cout <<"EliminarActual ";
                if (op == TipoOperacion::CambiarTda) std:: cout <<"CambiarTDA ";
                
                int puntajeCarta = carta.obtenerPuntaje();
                std::cout << "ptj:" << puntajeCarta << std::endl;

            }
        }

        void agregarCarta(Mazo& mazo) {
            mano.insertarFrente(mano.obtenerTamanio(),mazo.sacarCarta());
        }
        
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
#ifndef SALUD_H
#define SALUD_H

#include <iostream>
#include "TDAs/pila.h"
#include "TDAs/queue.h"
#include "TDAs/lista.h"

class Salud {
    public:
        Salud();

        void aplicarDanio(int danio);
        void aplicarCura(int cura);

        int obtenerVidaActual() const;

    private:
        Pila<int> pilaSalud;
        Queue<int> colaSalud;
        Lista<int> listaSalud;
};

#endif // SALUD_H
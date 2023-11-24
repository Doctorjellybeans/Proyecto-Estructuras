#ifndef CARTAS_H
#define CARTAS_H

#include <iostream>
#include <string>

enum class TipoOperacion {
    Apilar,
    InsertarActual,
    Encolar,
    Desapilar,
    Desencolar,
    EliminarActual,
    CambiarTda
};

enum class TipoCarta {
    DANIO,
    VIDA,
    EFECTO
};

class Carta {
    private:
        TipoOperacion operacion;
        TipoCarta tipo;
        int puntaje;

    public:
        // Constructor
        Carta(TipoCarta tipo, TipoOperacion op, int pts) : tipo(tipo), operacion(op), puntaje(pts) {}

        // Métodos de acceso
        TipoOperacion ObtenerOperacion() const {
            return operacion;
        }

        int ObtenerPuntaje() const {
            return puntaje;
        }
};

#endif // CARTAS_H
#ifndef TURNOS_H
#define TURNOS_H

#include "TDA-Oh/jugador.h"
#include "TDAs/mapa.h"

class Turno {
public:
    Turno(Jugador& jugador1, Jugador& jugador2);

    void jugarTurno();

private:
    Jugador& jugadorActivo;
    Jugador& jugadorNoActivo;
    Mapa<std::string, int> registroDanioCura;

    void ejecutarAccion(Carta& carta, Jugador& jugador);
    void cambiarTDA(Jugador& jugador, TipoOperacion nuevoTDA);
};

#endif // TURNOS_H
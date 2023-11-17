#ifndef CARTAS_H
#define CARTAS_H

#include <iostream>
#include <string>

// Enumeracion para los tipos de carta
enum TipoCarta {
    Danio,
    Recuperacion,
    Especial
};

// Clase base carta
class Carta {
public:
    Carta(TipoCarta tipo);

    /* En caso de agregar mas cosass (metodos?) */

private:
    TipoCarta tipo;
};

// Clase derivada para cartas de daño
class CartaDanio : public Carta {
public:
    CartaDanio(int puntosDanio);

private:
    int puntosDanio;
};

// Clase derivada para cartas de sanacion
class CartaRecuperacion : public Carta {
public:
    CartaRecuperacion(int puntosRecuperacion);

private:
    int puntosRecuperacion;
};

// Clase derivada para cartas especiales
class CartaEspecial : public Carta {
public:
    CartaEspecial(std::string descripcionEspecial);

};

#endif 

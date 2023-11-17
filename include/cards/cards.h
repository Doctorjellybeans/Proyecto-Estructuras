#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>

// Enumeracion para los tipos de carta
enum TypeOfCard {
    Damage,
    Healing,
    Special
};

// Clase base carta
class Card {
public:
    Card(TypeOfCard tipo);

    /* En caso de agregar mas cosas (metodos?) */

private:
    TypeOfCard tipo;
};

// Clase derivada para cartas de daño
class damageCard : public Card {
public:
    damageCard(int damagePoints);

private:
    int damagePoints;
};

// Clase derivada para cartas de sanacion
class healingCard : public Card {
public:
    healingCard(int healingPoints);

private:
    int healingPoints;
};

// Clase derivada para cartas especiales
class specialCard : public Card {
public:
    specialCard(std::string specialDescription);

};

#endif 

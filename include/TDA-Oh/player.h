#ifndef PLAYER_H
#define PLAYER_H

#include "TDAs/list.h"
#include "TDA-Oh/enum.h"

class Card;
class Deck;
class HealthBar;

class Player {
public:
    Player(int initialHealthPoints, TDAType initialTDA);
    ~Player();

    void receiveDamage(int damageAmount, TDACardOperation cardOperation);
    void heal(int healingAmount, TDACardOperation cardOperation);
    void changeTDA();

    void addCardToHand(Deck& deck);
    void playCard();
    int getHealth() const;
    TDAType getTDAType();

private:
    HealthBar* healthBar;
    List<Card*> hand;
};

#endif // PLAYER_H
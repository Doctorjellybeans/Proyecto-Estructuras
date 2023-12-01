#ifndef PLAYER_H
#define PLAYER_H

#include "TDAs/list.h"
#include "TDA-Oh/cards.h"
#include "TDA-Oh/health.h"
#include "TDA-Oh/deck.h"

#include <iostream>

class Player {
    private:
        HealthBar healthBar;
        List<Card*> hand;

    public:
        Player(int initialHealthPoints, TDAType initialTDA) : healthBar(initialHealthPoints, initialTDA) {}

        void receiveDamage(int damageAmount, TDACardOperation cardOperation) {
            healthBar.receiveDamage(damageAmount, cardOperation);
        }

        void heal(int healingAmount, TDACardOperation cardOperation) {
            healthBar.receiveDamage(healingAmount, cardOperation);
        }

        void changeTDA() {
            healthBar.changeNext();
        }

        void addCardToHand(Deck& deck) {
            Card* topCard = deck.drawCard();
            hand.pushFront(&topCard);
        }

        void playCard() {}

        int getHealth() const {
            return 0;
        }

        TDAType getTDAType() {
            return healthBar.getTDA();
        }
};

#endif // PLAYER_H

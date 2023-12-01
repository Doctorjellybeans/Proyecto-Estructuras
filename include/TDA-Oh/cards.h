#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include "TDA-Oh/player.h"
#include "TDA-Oh/enum.h"

class Card {
    private:
        TDACardOperation operation;

    public:
        Card(TDACardOperation cardOperation) : operation(cardOperation) {}

        virtual void applyEffect(Player& target) const = 0;

        TDACardOperation getCardOperation() const {
            return operation;
        }

        virtual ~Card() {}
};

class DamageCard : public Card {
    private:
        int damageAmount;

    public:
        DamageCard(TDACardOperation cardOperation, int damage) : Card(cardOperation), damageAmount(damage) {}

        void applyEffect(Player& target) const override {
            target.receiveDamage(damageAmount, getCardOperation());
        }
};

class HealCard : public Card {
    private:
        int healAmount;

    public:
        HealCard(TDACardOperation cardOperation, int heal) : Card(cardOperation), healAmount(heal) {}

        void applyEffect(Player& target) const override {
            target.heal(healAmount, getCardOperation());
        }
};

class EffectCard : public Card {
    public:
        EffectCard(TDACardOperation cardOperation) : Card(cardOperation) {}

        void applyEffect(Player& target) const override {
            target.changeTDA();
        }
};

#endif // CARDS_H

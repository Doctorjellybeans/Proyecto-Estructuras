#ifndef TURN_MANAGER_H
#define TURN_MANAGER_H

#include "TDAs/map.h"
#include "enum.h"
#include "TDA-Oh/cards.h"
#include <iostream>

typedef struct TurnNode {
    int number;
    int damageInflicted;
    int healingPoints;
} TurnNode;

class Turn {
public:
    Turn(int number) : info({number, 0, 0}) {}

    int getNumber() const {
        return info.number;
    }

    int getDamageInflicted() const {
        return info.damageInflicted;
    }

    int getHealingPoints() const {
        return info.healingPoints;
    }

    void applyAction(int damage, int healing) {
        info.damageInflicted += damage;
        info.healingPoints += healing;
    }

private:
    TurnNode info;

    Map<int,TurnNode> map;
};

#endif // TURN_MANAGER_H

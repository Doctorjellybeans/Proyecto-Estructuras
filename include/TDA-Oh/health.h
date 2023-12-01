#ifndef HEALTH_H
#define HEALTH_H

#include <algorithm>
#include <unordered_map>
#include "TDAs/stack.h"
#include "TDA-Oh/enum.h"

#include "TDAs/list.h"
#include "TDAs/queue.h"

class HealthBar {
public:
    HealthBar(int initialPoints, TDAType initialTDA);

    TDAType findInverseType( TDACardOperation operation);
    bool isMoveValid( TDAType tdaHP, TDACardOperation cardOperation);

    void changeNext();
    void receiveDamage(int damageAmount, TDACardOperation cardOperation);

    void heal(int healingAmount, TDACardOperation cardOperation);

    int getPoints();
    TDAType getTDA();

private:
    int points;

    Stack<int> stackHealth;
    Queue<int> queueHealth;
    List<int> listHealth;

    TDAType currentType;
};

#endif // HEALTH_H

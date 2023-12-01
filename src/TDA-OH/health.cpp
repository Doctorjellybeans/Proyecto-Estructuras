#include "TDA-OH/health.h"
#include "TDA-OH/cards.h"

HealthBar::HealthBar(int initialPoints, TDAType initialTDA)
    : points(initialPoints), currentType(initialTDA) {
            
    for (int i = 0; i < initialPoints; i++) {
        stackHealth.push(i, 1);
        queueHealth.push(i);
        listHealth.pushFront(&i);
    }
}

TDAType HealthBar::findInverseType( TDACardOperation operation) {
    std::unordered_map<TDACardOperation, TDAType> operationTypeMap = {
        {TDACardOperation::PUSH, TDAType::STACK},
        {TDACardOperation::POP, TDAType::STACK},
        {TDACardOperation::ENQUEUE, TDAType::QUEUE},
        {TDACardOperation::DEQUEUE, TDAType::QUEUE},
        {TDACardOperation::INSERT, TDAType::LIST},
        {TDACardOperation::DELETE, TDAType::LIST},
        {TDACardOperation::CHANGETDA, TDAType::SPECIAL}
    };

            
    // Search for the inverse operation in the map
    auto iterator = operationTypeMap.find(operation);

    // If found, return the associated type; otherwise, return a default value
    if (iterator != operationTypeMap.end()) {
        return iterator->second;
    } else {
        return TDAType::SPECIAL; 
    }
}

bool HealthBar::isMoveValid( TDAType tdaHP, TDACardOperation cardOperation) {
    TDAType comparison = findInverseType(cardOperation);

    return comparison == tdaHP;
}

void HealthBar::changeNext() {
    switch (currentType) {
    case TDAType::STACK:
        currentType = TDAType::QUEUE;
        break;
    case TDAType::QUEUE:
        currentType = TDAType::LIST;
        break;
    case TDAType::LIST:
        currentType = TDAType::STACK;
        break;
    }
}

void HealthBar::receiveDamage(int damageAmount, TDACardOperation cardOperation) {
    if (!isMoveValid(currentType, cardOperation)) {
        return;
    }
    
    for (int i = 0; i < damageAmount; i++) {
        stackHealth.pop();
        queueHealth.pop();
        listHealth.popFront();
    }

    points -= damageAmount;
    if (points < 0) {
        points = 0;
    }

}

void HealthBar::heal(int healingAmount, TDACardOperation cardOperation) {
    if (isMoveValid(currentType, cardOperation)) {
        int top = points + healingAmount;
        for (int i = points; i < top; i++) {
            stackHealth.push(i, 1);
            queueHealth.push(i);
            listHealth.pushBack(&i);
        }
        points += healingAmount;
        if (points > 20) {
            points = 20;
        }
    }
}

int HealthBar::getPoints() {
    return points;
}

TDAType HealthBar::getTDA() {
    return currentType;
}
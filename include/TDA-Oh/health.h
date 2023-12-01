#ifndef HEALTH_H
#define HEALTH_H

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "TDAs/stack.h"
#include "TDA-OH/cards.h"
#include "TDAs/queue.h"
#include "TDAs/list.h"
#include "TDA-Oh/enum.h"

class HealthBar {
    private:
        int points;

        Stack<int> stackHealth;
        Queue<int> queueHealth;
        List<int> listHealth;

        TDAType currentType;

    public:
        HealthBar(int initialPoints, TDAType initialTDA) : points(initialPoints), currentType(initialTDA) {
            
            for (int i = 0; i < initialPoints; i++) {
                stackHealth.push(i, 1);
                queueHealth.push(i);
                listHealth.pushFront(&i);
            }
        }

        TDAType findInverseType( TDACardOperation operation) {
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

        bool isMoveValid( TDAType tdaHP, TDACardOperation cardOperation) {
            TDAType comparison = findInverseType(cardOperation);

            return comparison == tdaHP;
        }

        void changeNext() {
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

        void receiveDamage(int damageAmount, TDACardOperation cardOperation) {
            if (isMoveValid(currentType, cardOperation)){
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
        }

        void heal(int healingAmount, TDACardOperation cardOperation) {
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

        int getPoints() {
            return points;
        }

        TDAType getTDA() {
            return currentType;
        }
};

#endif // HEALTH_H

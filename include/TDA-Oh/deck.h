#ifndef DECK_H
#define DECK_H

#include "TDAs/stack.h"
#include "TDA-Oh/cards.h"
#include "TDA-Oh/enum.h"
#include <random>

class Deck {
    private:
        Stack<Card*> deck;

        int randomNumer(int num) const {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribution(1, num);

            return distribution(gen);
        }

        TDACardOperation randomOperation(TDAType type) const {
            TDACardOperation operation;

            switch (type) {
                case TDAType::STACK:
                    static const TDACardOperation stackOperations[] = {TDACardOperation::POP, TDACardOperation::PUSH};
                    operation = stackOperations[randomNumer(2)];
                    break;
                case TDAType::QUEUE:
                    static const TDACardOperation queueOperations[] = {TDACardOperation::ENQUEUE, TDACardOperation::DEQUEUE};
                    operation = queueOperations[randomNumer(2)];
                    break;
                case TDAType::LIST:
                    static const TDACardOperation listOperations[] = {TDACardOperation::INSERT, TDACardOperation::DELETE};
                    operation = listOperations[randomNumer(2)];
                    break;
                case TDAType::SPECIAL:
                    static const TDACardOperation specialOperations[] = {TDACardOperation::CHANGETDA};
                    operation = specialOperations[0];
            }

            return operation;
        }

    public:
        void fillDeck() {
            for (int i = 0; i < 56; i++) {
                int option = randomNumer(3);

                if (option == 1) { // DAMAGE CARD
                    // More TDAs are missing
                    DamageCard* damageCard = new DamageCard(randomOperation(TDAType::STACK), randomNumer(3));
                    deck.push(i, damageCard);

                } else if (option == 2) { // HEAL CARD
                    // More TDAs are missing
                    HealCard* healCard = new HealCard(randomOperation(TDAType::STACK), randomNumer(3));
                    deck.push(i, healCard);

                } else if (option == 3) { // SPECIAL CARD
                    EffectCard* effectCard = new EffectCard(TDACardOperation::CHANGETDA);
                    deck.push(i, effectCard);
                }
            }
        }

        Card* drawCard() {
            if (!deck.isEmpty()) {
                Card* card = deck.pop();
                return card;
            } else {
                fillDeck();
                return nullptr;
            }
        }

        bool isEmpty() {
            return deck.isEmpty();
        }
};

#endif // DECK_H

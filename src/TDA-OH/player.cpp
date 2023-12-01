#include "TDA-Oh/player.h"

#include "TDA-Oh/deck.h"
#include "TDA-Oh/health.h"

Player::Player(int initialHealthPoints, TDAType initialTDA) {
    this->healthBar = new HealthBar(initialHealthPoints, initialTDA);
}

Player::~Player() {
    delete healthBar;
}

void Player::receiveDamage(int damageAmount, TDACardOperation cardOperation) {
    healthBar->receiveDamage(damageAmount, cardOperation);
}

void Player::heal(int healingAmount, TDACardOperation cardOperation) {
    healthBar->receiveDamage(healingAmount, cardOperation);
}

void Player::changeTDA() {
   healthBar->changeNext();
}

void Player::addCardToHand(Deck& deck) {
    Card* topCard = deck.drawCard();
    hand.pushFront(&topCard);
}

void Player::playCard() {}

int Player::getHealth() const {
    return 0;
}

TDAType Player::getTDAType() {
    return healthBar->getTDA();
}
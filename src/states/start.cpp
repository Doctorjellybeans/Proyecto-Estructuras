#include "states/start.h"


StartState::StartState() {
    this->window = new RenderWindow("TDA-OH!", 800, 600);

    title.set_text("TDA_OH!");
    title.set_size(70);
    title.set_position(250, 120);
}

StartState::~StartState() {
    delete this->window;
}

void StartState::update() {

}

void StartState::render() {
    this->window->draw(title);
}

void StartState::clear() {
    this->window->display();
    this->window->clear();
}
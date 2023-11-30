#include "application.h"
#include "states/start.h"
#include "util.h"

Application::Application() {
    State* start = new StartState(&states);
    this->states.push(start);
}

Application::~Application() {
    while (!this->states.empty())
    {
        delete currentState();
        this->states.pop();
    }
}

// Bucle principal de la aplicación
void Application::run() {

    while (!this->states.empty())
    {
        currentState()->pollEvents();

        update();
        render();

        if (!this->states.empty()) {
            currentState()->clear();
        }
    }
}

void Application::update() {
    State* state = currentState();
    
    if(!state->hasEnded()) {
        state->update();
    } else {
        this->states.pop();
        delete state;
    }
}

void Application::render() {
    if (!this->states.empty()) {
        currentState()->render();
    }
}
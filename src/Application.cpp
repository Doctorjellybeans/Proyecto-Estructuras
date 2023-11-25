#include "application.h"
#include "states/start.h"

Application::Application() {
    State* start = new StartState();
    this->states.push(start);
}

Application::~Application() {
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Application::run() {

    while (!this->states.empty())
    {
        while(SDL_PollEvent(&this->event))
        {
            pollEvents();
        }

        update();
        render();

        if (!this->states.empty()) {
            this->states.top()->clear();
        }
    }
}

void Application::update() {
    State* state = this->states.top();
    
    if(!state->hasEnded()) {
        state->update();
    } else {
        this->states.pop();
        delete state;
    }
}

void Application::render() {

    if (!this->states.empty()) {
        this->states.top()->render();
    }
}

void Application::pollEvents() {
    switch (event.type)
    {
    case SDL_QUIT:
        this->states.top()->end();
        break;
    }
}
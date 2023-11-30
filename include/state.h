#ifndef STATE_H
#define STATE_H

#include "TDAs/queue.h"
void success(const char* fmt, ...);

class State;
typedef Queue<State*> StateQueue;

class State {

public:

    State(): quited(false)  {}
    virtual ~State() {};

    // Metodos abtractos
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void clear()  = 0;
    virtual void pollEvents() = 0;
    /////
    
    inline void end() { quited = true; }
    inline bool hasEnded() const { return this->quited; }

    void pushState(State* state) {
        if (origin != nullptr) {
            origin->push(state);
        }
    }

protected:
    
    // 'orgin' se trata de la cola original
    // de 'State's. Este es en el caso de
    // que algun estado requiera añadir otro.
    Queue<State*>* origin = nullptr;

private:

    bool quited;
};

#endif //STATE_H
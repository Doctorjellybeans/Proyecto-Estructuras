#ifndef STATE_H
#define STATE_H

#include "TDAs/queue.h"
void success(const char* fmt, ...);

class State {

public:

    State(): quited(false)  {}
    virtual ~State() { success("¡Estado cerrado!"); };

    virtual void render() = 0;
    virtual void update() = 0;
    virtual void clear()  = 0;
    
    inline void end() { quited = true; }
    inline bool hasEnded() const { return this->quited; }

    void pushState(State* state) {
        if (origin != nullptr) {
            origin->push(state);
        }
    }

protected:

    Queue<State*>* origin = nullptr;

private:

    bool quited;
};

typedef Queue<State*> StateQueue;

#endif //STATE_H
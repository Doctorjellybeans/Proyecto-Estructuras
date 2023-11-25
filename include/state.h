#ifndef STATE_H
#define STATE_H

class State {

public:

    State() { this->quited = false; }
    virtual ~State() = default;

    virtual void render() = 0;
    virtual void update() = 0;
    virtual void clear()  = 0;
    
    inline void end() { quited = true; }
    inline bool hasEnded() const { return this->quited; }

private:

    bool quited;
};

#endif //STATE_H
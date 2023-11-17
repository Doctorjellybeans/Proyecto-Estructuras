#ifndef STATE_H
#define STATE_H

class State {

public:

    State() { this->quited = false; }
    virtual ~State() = default;

    virtual void render() = 0;
    virtual void update() = 0;
    
    inline void end() { quited = true; }
    inline bool has_ended() const { return quited; }

private:

    bool quited;
};

#endif //STATE_H
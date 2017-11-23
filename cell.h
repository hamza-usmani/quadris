#ifndef cell_h
#define cell_h

#include <vector>
#include "observer.h"

class Block;
enum State{ NONE = ' ', I = 'I', J = 'J', L = 'L', O = 'O', S = 'S', Z = 'Z', T = 'T' };

class Cell{
    State cellState;
    Block *cur;
    
    std::vector<Observer*> observers;
    
    public:
    Cell();
    State getState();
    Block *getCur();
    void setCur(Block *changeTo);
    
    void attach(Observer *o);
    void notifyObservers();
};

#endif 

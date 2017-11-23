#ifndef cell_h
#define cell_h

#include <vector>
#include "observer.h"

class Block;
enum State{ NONE = ' ', I = 'I', J = 'J', L = 'L', O = 'O', S = 'S', Z = 'Z', T = 'T' };

struct Pos{
    int x;
    int y;
};

class Cell{
    Pos position;
    State cellState;
    Block *cur;
    std::vector<Observer*> observers;
    
    public:
    Cell(int width, int height);
    Pos getPosition();
    State getState();
    Block *getCur();
    void setCur(Block *changeTo);
    
    void attach(Observer *o);
    void notifyObservers();
};

#endif 

#ifndef block_h
#define block_h

#include <vector>
#include "cell.h"
#include "Level.h"

struct Pos;

class Block{
    int count;
    std::vector<Pos> position;
    Pos leftCorner;
    int levelCreated;
    bool isHeavy;
    
    public:
    Block(int levelCreated);
    
    //getters:
    int getCount();
    Pos getLeftCorner();
    int getLevelCreated();
    
    //transormations
    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
};

#endif

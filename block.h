#ifndef block_h
#define block_h

#include <vector>
#include "cell.h"
#include "Level.h"

struct Pos;

class Block{
    int count;
    int levelCreated;
    bool isHeavy;
    char blockChar;
    
    protected:
    std::vector<Pos> position;
    Pos leftCorner;
    
    public:
    Block(int levelCreated, char blockChar);
    
    //getters & setters
    int getCount();
    void increaseCount();
    int getLevelCreated();
    bool getIsHeavy();
    char getBlockChar();
    std::vector<Pos> getPositions();
    Pos getLeftCorner();
    
    //transormations
    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
};

#endif

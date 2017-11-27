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
    int width;
    int height;
    std::vector<Pos> position;
    Pos leftCorner;
    int orientation;
    
    public:
    Block(int levelCreated, char blockChar, int width, int height);
    
    //setters & transformations
    void increaseCount();
    void moveDown(int y);
    void moveHorizontally(int x);
    virtual void rotateClockwise() = 0;
    virtual void rotateCounterclockwise() = 0;
    
    //getters
    int getCount();
    int getLevelCreated();
    bool getIsHeavy();
    char getBlockChar();
    std::vector<Pos> getPositions();
    Pos getLeftCorner();
    int getWidth();
    int getHeight();

};

#endif

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
    int width;
    int height;
    
    protected:
    std::vector<Pos> position;
    Pos leftCorner;
    
    public:
    Block(int levelCreated, char blockChar, int width, int height);
    //Block(int count, int levelCreated, char blockChar, int width, int height, std::vector<Pos> position, Pos leftCorner);
    
    //setters
    void increaseCount();
    void moveDown(int y);
    
    //getters
    int getCount();
    int getLevelCreated();
    bool getIsHeavy();
    char getBlockChar();
    std::vector<Pos> &getPositions();
    Pos getLeftCorner();
    int getWidth();
    int getHeight();
    
    //pure virtual functions
    virtual void clockwise() = 0;
    virtual void counterclockwise() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
};

#endif

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
    
    //setters & transformations
    void increaseCount();
    void moveDown(int y);
    void moveHorizontally(int x);
    void clockwise();
    void counterclockwise();
    
    //getters
    int getCount();
    int getLevelCreated();
    bool getIsHeavy();
    char getBlockChar();
    std::vector<Pos> &getPositions();
    Pos getLeftCorner();
    int getWidth();
    int getHeight();

};

#endif

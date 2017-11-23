#ifndef block_h
#define block_h

#include <vector>
#include "cell.h"

struct Pos{
    int x;
    int y;
};

class Block{
    int count;
    std::vector<Pos> position;
    Pos leftCorner;
    //LevelList levelCreated;
    
    public:
    //Block(LevelList levelCreated) this is the format for all sublcass constructors
    
    //getters:
    int getCount();
    Pos getLeftCorner();
    //LevelList getLevelCreated();
    
    //transormations
    //virtual clockwise() = 0;
    //virtual counterclockwise() = 0;
    //virtual moveLeft() = 0;
    //virtual moveRight() = 0;
    //virtual moveDown() = 0;
};

#endif

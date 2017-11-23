#ifndef lblock_h
#define lblock_h

#include "block.h"

class LBlock: public Block{
    public:
    LBlock(int levelCreated);
    void clockwise() override;
    void counterclockwise() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif

#ifndef tblock_h
#define tblock_h

#include "block.h"

class TBlock: public Block{
    public:
    TBlock(int levelCreated);
    void clockwise() override;
    void counterclockwise() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif

#ifndef sblock_h
#define sblock_h

#include "block.h"

class SBlock: public Block{
    public:
    SBlock(int levelCreated);
    void clockwise() override;
    void counterclockwise() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif

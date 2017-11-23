#ifndef zblock_h
#define zblock_h

#include "block.h"

class ZBlock: public Block{
    public:
    ZBlock(int levelCreated);
    void clockwise() override;
    void counterclockwise() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif

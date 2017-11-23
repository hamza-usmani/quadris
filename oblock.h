#ifndef oblock_h
#define oblock_h

#include "block.h"

class OBlock: public Block{
    public:
    OBlock(int levelCreated);
    void clockwise() override;
    void counterclockwise() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif

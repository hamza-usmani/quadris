#ifndef jblock_h
#define jblock_h

#include "block.h"

class JBlock: public Block{
    public:
    JBlock(int levelCreated);
    void clockwise() override;
    void counterclockwise() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif

#ifndef iblock_h
#define iblock_h

#include "block.h"

class IBlock: public Block{
    public:
    IBlock(int levelCreated);
    void clockwise() override;
    void counterclockwise() override;
    void moveLeft() override;
    void moveRight() override;
    void moveDown() override;
};

#endif

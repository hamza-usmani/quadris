#ifndef zblock_h
#define zblock_h

#include "block.h"

class ZBlock: public Block{
    void orientation_0(Pos leftCorner, std::vector<Pos> &newPositions);
    void orientation_1(Pos leftCorner, std::vector<Pos> &newPositions);
    
    public:
    ZBlock(int levelCreated);
    void rotateClockwise() override;
    void rotateCounterclockwise() override;
    
    std::vector<std::vector<State>> printBlock() override;
};

#endif

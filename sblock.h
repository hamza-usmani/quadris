#ifndef sblock_h
#define sblock_h

#include "block.h"

class SBlock: public Block{
    void orientation_0(Pos leftCorner, std::vector<Pos> &newPositions);
    void orientation_1(Pos leftCorner, std::vector<Pos> &newPositions);
    
    public:
    SBlock(int levelCreated);
    void rotateClockwise() override;
    void rotateCounterclockwise() override;
    
    std::vector<std::vector<State>> printBlock() override;
};

#endif

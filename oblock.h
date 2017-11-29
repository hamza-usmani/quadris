#ifndef oblock_h
#define oblock_h

#include "block.h"

class OBlock: public Block{
    public:
    OBlock(int levelCreated);
    void rotateClockwise() override;
    void rotateCounterclockwise() override;
    
    std::vector<std::vector<State>> printBlock() override;
};

#endif

#ifndef blankblock_h
#define blankblock_h

#include "block.h"

class BlankBlock: public Block{
public:
    BlankBlock(int levelCreated);
    void rotateClockwise() override;
    void rotateCounterclockwise() override;
    
    std::vector<std::vector<State>> printBlock() override;
};

#endif


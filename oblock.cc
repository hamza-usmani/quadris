#include "oblock.h"

OBlock::OBlock(int levelCreated): Block(levelCreated, 'o', 2, 2){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,2});
}

void OBlock::rotateClockwise(){ }

void OBlock::rotateCounterclockwise(){ }

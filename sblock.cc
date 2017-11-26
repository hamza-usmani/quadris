#include "sblock.h"

SBlock::SBlock(int levelCreated):Block(levelCreated, 's', 3, 2){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{1,2});
    this->position.emplace_back(Pos{2,2});
}


#include "lblock.h"

LBlock::LBlock(int levelCreated):Block(levelCreated, 'l', 3, 2){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{2,3});
    this->position.emplace_back(Pos{2,2});
}


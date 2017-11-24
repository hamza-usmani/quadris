#include "zblock.h"

ZBlock::ZBlock(int levelCreated):Block(levelCreated, 'z'){
    this->position.pop_back();
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{2,3});
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,2});
}

void ZBlock::clockwise(){
    
}

void ZBlock::counterclockwise(){
    
}

void ZBlock::moveLeft(){
    
}

void ZBlock::moveRight(){
    
}

void ZBlock::moveDown(){
    
}

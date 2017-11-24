#include "sblock.h"

SBlock::SBlock(int levelCreated):Block(levelCreated, 's'){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,2});
}

void SBlock::clockwise(){
    
}

void SBlock::counterclockwise(){
    
}

void SBlock::moveLeft(){
    
}

void SBlock::moveRight(){
    
}

void SBlock::moveDown(){
    
}

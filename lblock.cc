#include "lblock.h"

LBlock::LBlock(int levelCreated):Block(levelCreated, 'l'){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{2,3});
    this->position.emplace_back(Pos{2,2});
}

void LBlock::clockwise(){
    
}

void LBlock::counterclockwise(){
    
}

void LBlock::moveLeft(){
    
}

void LBlock::moveRight(){
    
}

void LBlock::moveDown(){
    
}

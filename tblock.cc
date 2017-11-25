#include "tblock.h"

TBlock::TBlock(int levelCreated):Block(levelCreated, 't', 3, 2){
    this->position.pop_back();
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,2});
    this->position.emplace_back(Pos{2,2});
}

void TBlock::clockwise(){
    
}

void TBlock::counterclockwise(){
    
}

void TBlock::moveLeft(){
    
}

void TBlock::moveRight(){
    
}

void TBlock::moveDown(){
    
}

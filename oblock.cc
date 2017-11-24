#include "oblock.h"

OBlock::OBlock(int levelCreated): Block(levelCreated, 'o'){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,2});
}

void OBlock::clockwise(){
    
}

void OBlock::counterclockwise(){
    
}

void OBlock::moveLeft(){
    
}

void OBlock::moveRight(){
    
}

void OBlock::moveDown(){
    
}

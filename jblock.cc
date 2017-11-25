#include "jblock.h"

JBlock::JBlock(int levelCreated):Block(levelCreated, 'j', 3, 2){
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{2,3});
}

void JBlock::clockwise(){
    
}

void JBlock::counterclockwise(){
    
}

void JBlock::moveLeft(){
    
}

void JBlock::moveRight(){
    
}

void JBlock::moveDown(){
    
}

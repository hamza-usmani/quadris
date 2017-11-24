#include "iblock.h"

IBlock::IBlock(int levelCreated):Block(levelCreated, 'i'){
    for (int i=0; i<3; i++) this->position.emplace_back(Pos{0,i});
}

void IBlock::clockwise(){
	
}

void IBlock::counterclockwise(){
	
}

void IBlock::moveLeft(){
	
}

void IBlock::moveRight(){
	
}

void IBlock::moveDown(){
	
}

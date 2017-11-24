#include "block.h"

Block::Block(int levelCreated, char blockChar) {
    this->count = 0;
    Pos corner{0,3};
    this->position.emplace_back(corner);
    this->leftCorner = corner;
    this->levelCreated = levelCreated;
    this->blockChar = blockChar;
    this->isHeavy = this->levelCreated < 3 ? false: true;
}

int Block::getCount(){
    return this->count;
}

void Block::increaseCount(){
    this->count++;
}

int Block::getLevelCreated() {
    return this->levelCreated;
}

bool Block::getIsHeavy(){
    return this->isHeavy;
}

char Block::getBlockChar(){
    return this->blockChar;
}

std::vector<Pos> Block::getPositions(){
    return this->position;
}

Pos Block::getLeftCorner(){
    return this->leftCorner;
}



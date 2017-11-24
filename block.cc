#include "block.h"

Block::Block(int levelCreated) {
    count = 0;
    Pos corner{3,0};
    position.emplace_back(corner);
    leftCorner = corner;
    this->levelCreated = levelCreated;
}

int Block::getCount(){
    return this->count;
}

Pos Block::getLeftCorner(){
    return this->leftCorner;
}

int Block::getLevelCreated() {
    return this->levelCreated;
}


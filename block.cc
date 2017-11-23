#include "block.h"

int Block::getCount(){
    return this->count;
}

Pos Block::getLeftCorner(){
    return this->leftCorner;
}

int Block::getLevelCreated() {
    return this->levelCreated;
}


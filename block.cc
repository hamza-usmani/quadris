#include "block.h"
#include <iostream>
#include <algorithm>

Block::Block(int levelCreated, char blockChar, int width, int height) {
    this->count = 0;
    Pos corner{0,3};
    this->position.emplace_back(corner);
    this->leftCorner = Pos{0,3};
    this->levelCreated = levelCreated;
    this->width = width;
    this->height = height;
    this->blockChar = blockChar;
    this->isHeavy = this->levelCreated < 3 ? false: true;
    this->orientation = 0;
}

void Block::increaseCount(){
    this->count++;
}

void Block::moveDown(int y){
    this->leftCorner.y += y;
    for (auto &i: this->position){
        i.y += y;
    }
}

void Block::moveHorizontally(int x){
    this->leftCorner.x += x;
    for (auto &i: this->position){
        i.x += x;
    }
}

int Block::getCount(){
    return this->count;
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

int Block::getWidth(){
    return this->width;
}
int Block::getHeight(){
    return this->height;
}




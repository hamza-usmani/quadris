#include "sblock.h"

SBlock::SBlock(int levelCreated):Block(levelCreated, 's', 3, 2){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{1,2});
    this->position.emplace_back(Pos{2,2});
}

void SBlock::orientation_0(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y-1});
}

void SBlock::orientation_1(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-2});
}

void SBlock::rotateClockwise(){
    std::vector<Pos> newPositions;
    
    if (orientation == 0){
        orientation_1(leftCorner, newPositions);
        orientation++;
    }
    else if (orientation == 1){
        orientation_0(leftCorner, newPositions);
        orientation = 0;
    }
    position = newPositions;
    int heightTmp = height;
    height = width;
    width = heightTmp;
}

void SBlock::rotateCounterclockwise(){
    this->rotateClockwise();
}


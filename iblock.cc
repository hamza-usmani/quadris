#include "iblock.h"

IBlock::IBlock(int levelCreated):Block(levelCreated, 'i', 4, 1){
    for (int i=1; i<4; i++) {
        this->position.emplace_back(Pos{i,3});
    }
}

void IBlock::orientation_0(Pos leftCorner, std::vector<Pos> &newPositions){
    for (int i=1; i<4; i++){
        newPositions.emplace_back(Pos{leftCorner.x+i, leftCorner.y});
    }
}

void IBlock::orientation_1(Pos leftCorner, std::vector<Pos> &newPositions){
    for (int i=1; i<4; i++){
        newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-i});
    }
}


void IBlock::rotateClockwise(){
    std::vector<Pos> newPositions;
    newPositions.emplace_back(leftCorner);
    
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

void IBlock::rotateCounterclockwise(){
    this->rotateClockwise();
}


std::vector<std::vector<State>> IBlock::printBlock(){
    std::vector<std::vector<State>> tmp;
    std::vector<State> row1{State::I, State::I, State::I, State::I};
    tmp.emplace_back(row1);
    return tmp;
}


#include "zblock.h"

ZBlock::ZBlock(int levelCreated):Block(levelCreated, 'z', 3, 2){
    this->position.pop_back();
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{2,3});
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,2});
}

void ZBlock::orientation_0(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
}

void ZBlock::orientation_1(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-2});
}

void ZBlock::rotateClockwise(){
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

void ZBlock::rotateCounterclockwise(){
    this->rotateClockwise();
}


std::vector<std::vector<State>> ZBlock::printBlock(){
    std::vector<std::vector<State>> tmp;
    std::vector<State> row1{State::Z, State::Z, State::NONE};
    std::vector<State> row2{State::NONE, State::Z, State::Z};
    tmp.emplace_back(row1);
    tmp.emplace_back(row2);
    return tmp;
}

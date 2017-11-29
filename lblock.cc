#include "lblock.h"

LBlock::LBlock(int levelCreated):Block(levelCreated, 'l', 3, 2){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{2,3});
    this->position.emplace_back(Pos{2,2});
}

void LBlock::orientation_0(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y-1});
}

void LBlock::orientation_1(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-2});
}

void LBlock::orientation_2(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y-1});
}

void LBlock::orientation_3(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-2});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-2});
}

void LBlock::rotateClockwise(){
    std::vector<Pos> newPositions;
    
    if (orientation == 0){
        orientation_1(leftCorner, newPositions);
        orientation++;
    }
    else if (orientation == 1){
        orientation_2(leftCorner, newPositions);
        orientation++;
    }
    else if (orientation == 2){
       orientation_3(leftCorner, newPositions);
        orientation++;
    }
    else if (orientation == 3){
        orientation_0(leftCorner, newPositions);
        orientation = 0;
    }
    position = newPositions;
    int heightTmp = height;
    height = width;
    width = heightTmp;
}


void LBlock::rotateCounterclockwise(){
    std::vector<Pos> newPositions;
    
    if (orientation == 0){
        orientation_3(leftCorner, newPositions);
        orientation = 3;
    }
    else if (orientation == 1){
        orientation_0(leftCorner, newPositions);
        orientation--;
    }
    else if (orientation == 2){
        orientation_1(leftCorner, newPositions);
        orientation--;
    }
    else if (orientation == 3){
        orientation_2(leftCorner, newPositions);
        orientation--;
    }
    position = newPositions;
    int heightTmp = height;
    height = width;
    width = heightTmp;
    
    
}

std::vector<std::vector<State>> LBlock::printBlock(){
    std::vector<std::vector<State>> tmp;
    std::vector<State> row1{State::NONE, State::NONE, State::L};
    std::vector<State> row2{State::L, State::L, State::L};
    tmp.emplace_back(row1);
    tmp.emplace_back(row2);
    return tmp;
}

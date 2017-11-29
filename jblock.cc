#include "jblock.h"

JBlock::JBlock(int levelCreated):Block(levelCreated, 'j', 3, 2){
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{2,3});
}

void JBlock::orientation_0(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
}

void JBlock::orientation_1(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-2});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-2});
}

void JBlock::orientation_2(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(Pos{leftCorner.x, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+2, leftCorner.y});
    
}

void JBlock::orientation_3(Pos leftCorner, std::vector<Pos> &newPositions){
    newPositions.emplace_back(leftCorner);
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-1});
    newPositions.emplace_back(Pos{leftCorner.x+1, leftCorner.y-2});
}

void JBlock::rotateClockwise(){
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
    
    this->position = newPositions;
    int heightTmp = height;
    height = width;
    width = heightTmp;
}

void JBlock::rotateCounterclockwise(){
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
    
    this->position = newPositions;
    int heightTmp = height;
    height = width;
    width = heightTmp;
    
}

std::vector<std::vector<State>> JBlock::printBlock(){
    std::vector<std::vector<State>> tmp;
    std::vector<State> row1{State::J, State::NONE, State::NONE};
    std::vector<State> row2{State::J, State::J, State::J};
    tmp.emplace_back(row1);
    tmp.emplace_back(row2);
    return tmp;
}

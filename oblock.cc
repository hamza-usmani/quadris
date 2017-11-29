#include "oblock.h"

OBlock::OBlock(int levelCreated): Block(levelCreated, 'o', 2, 2){
    this->position.emplace_back(Pos{1,3});
    this->position.emplace_back(Pos{0,2});
    this->position.emplace_back(Pos{1,2});
}

void OBlock::rotateClockwise(){ }

void OBlock::rotateCounterclockwise(){ }

std::vector<std::vector<State>> OBlock::printBlock(){
    std::vector<std::vector<State>> tmp;
    std::vector<State> row1{State::O, State::O};
    std::vector<State> row2{State::O, State::O};
    tmp.emplace_back(row1);
    tmp.emplace_back(row2);
    return tmp;
}

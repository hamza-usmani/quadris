#include "blankblock.h"

BlankBlock::BlankBlock(int levelCreated):Block(levelCreated, '*', 1, 1){ }


void BlankBlock::rotateClockwise(){ }

void BlankBlock::rotateCounterclockwise(){ }

std::vector<std::vector<State>> BlankBlock::printBlock(){
    std::vector<std::vector<State>> tmp;
    std::vector<State> row1{State::Star};
    tmp.emplace_back(row1);
    return tmp;
}

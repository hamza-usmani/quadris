#include "iblock.h"

IBlock::IBlock(int levelCreated):Block(levelCreated, 'i', 4, 1){
    for (int i=1; i<4; i++) this->position.emplace_back(Pos{i,3});
}

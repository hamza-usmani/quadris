#include "Level_0.h"
#include "block.h" 

Level_0::Level_0(std::vector<char> &sequence): Level(0, sequence, 0, false) { }

Block *Level_0::createBlock(){
    if (index > sequence.size() - 1) return nullptr;

    char curChar = sequence.at(index);
    index++;

    if (index == sequence.size()) index = 0;

    if (curChar == 'i' || curChar == 'I') return create_I_Block();
    else if (curChar == 'j' || curChar == 'J') return create_J_Block();
    else if (curChar == 'l' || curChar == 'L') return create_L_Block();
    else if (curChar == 'o' || curChar == 'O') return create_O_Block();
    else if (curChar == 's' || curChar == 'S') return create_S_Block();
    else if (curChar == 'z' || curChar == 'Z') return create_Z_Block();
    else return create_T_Block();
}



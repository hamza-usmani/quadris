#include "Level.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include <string>

Level::Level(int LevelDifficulty, std::vector<char> sequence, int index, bool gen_rand):
    LevelDifficulty(LevelDifficulty), sequence(sequence), index(index), gen_rand(gen_rand) {}

int Level::getLevel(){
    return this->LevelDifficulty;
}

Block *Level::create_I_Block(){
    Block *i = new IBlock(LevelDifficulty);
    return i;
}

Block *Level::create_J_Block(){
    Block *j = new JBlock(LevelDifficulty);
    return j;
}

Block *Level::create_L_Block(){
    Block *l = new LBlock(LevelDifficulty);
    return l;
}

Block *Level::create_O_Block(){
    Block *o = new OBlock(LevelDifficulty);
    return o;
}

Block *Level::create_S_Block(){
    Block *s = new SBlock(LevelDifficulty);
    return s;
}

Block *Level::create_Z_Block(){
    Block *z = new ZBlock(LevelDifficulty);
    return z;
}

Block *Level::create_T_Block(){
    Block *t = new TBlock(LevelDifficulty);
    return t;
}


void Level::randomOn() {
    if (LevelDifficulty == 0) return;
    gen_rand = true;
}

void Level::randomOff(const std::vector<char> vec) {
    if (LevelDifficulty == 0) return;
    sequence = vec;
    index = 0;
    gen_rand = false;
}

Block *Level::changeCurrentBlock(std::string blockChar){
    if (blockChar == "I" || blockChar == "i") return create_I_Block();
    else if (blockChar == "J" || blockChar == "j") return create_J_Block();
    else if (blockChar == "L" || blockChar == "l") return create_L_Block();
    else if (blockChar == "O" || blockChar == "o") return create_O_Block();
    else if (blockChar == "S" || blockChar == "s") return create_S_Block();
    else if (blockChar == "Z" || blockChar == "z") return create_Z_Block();
    else if (blockChar == "T" || blockChar == "t") return create_T_Block();
    else return nullptr;
}

Level::~Level() {}

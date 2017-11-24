#include "Level.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

Level::Level(int LevelDifficulty): LevelDifficulty(LevelDifficulty) {}

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

Level::~Level() {}



#ifndef LEVEL 
#define LEVEL

#include <cstdlib>
#include <vector>
#include "block.h"

// Abstract base class
class Level{
    protected:
    int LevelDifficulty; //one of 0,1,2,3,4

/*
	Block create_I_Block();
	Block create_J_Block();
	Block create_L_Block();
	Block create_O_Block();
	Block create_S_Block();
	Block create_Z_Block();
	Block create_T_Block();
*/

    public:
	//virtual Block createBlock(); TODO: for level 1+
    virtual Block *createBlock_from_seq(std::vector<char> &sequence);
    int getLevel();
	~Level();
};

#endif

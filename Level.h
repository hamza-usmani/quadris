#ifndef LEVEL 
#define LEVEL

#include <cstdlib>
#include <vector>
#include "block.h"

// Abstract base class
class Level(){
	Block create_I_Block();
	Block create_J_Block();
	Block create_L_Block();
	Block create_O_Block();
	Block create_S_Block();
	Block create_Z_Block();
	Block create_T_Block();

	void makeHeavy(Block &block); //modifies existing block to heavy

public:
	virtual Block createBlock() = 0;
    virtual Block createBlock_from_seq(std::vector<char> &sequence);
	~Level();
};

#endif

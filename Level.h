#ifndef LEVEL 
#define LEVEL
#include <cstdlib>


// Abstract base class
class Level(){
	virtual Block create_I_Block();
	virtual Block create_J_Block();
	virtual Block create_L_Block();
	virtual Block create_O_Block();
	virtual Block create_S_Block();
	virtual Block create_Z_Block();
	virtual Block create_T_Block();

	virtual void makeHeavy(Block &block); //modifies existing block to heavy
public:
	virtual Block createBlock() = 0;
	virtual Block createBlock_from_seq(vector<char> &sequence);
	~Level();
}

#endif

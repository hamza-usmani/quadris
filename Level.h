#ifndef LEVEL 
#define LEVEL
#include <cstdlib>


// Abstract base class
class Level(){
	Block createBlock() = 0;
	Block createBlock_from_seq(vector &sequence);
	~Level();
}

#endif

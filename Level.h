#ifndef LEVEL 
#define LEVEL
#include 


// Abstract base class
class Level(){
	Block createBlock() = 0;
	~Level();
}

#endif

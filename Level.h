#ifndef LEVEL 
#define LEVEL
#include <cstdlib>


// Abstract base class
class Level(){
public:
	virtual Block createBlock() = 0;
	virtual Block createBlock_from_seq(vector<char> &sequence);
	~Level();
}

#endif

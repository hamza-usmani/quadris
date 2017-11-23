#ifndef LEVEL 
#define LEVEL

#include <cstdlib>
#include <vector>
#include "block.h"

// Abstract base class
class Level{
public:
	virtual Block createBlock() = 0;
    virtual Block createBlock_from_seq(std::vector<char> &sequence);
	~Level();
};

#endif

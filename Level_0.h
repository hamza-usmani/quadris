#ifndef LEVEL_0
#define LEVEL_0

#include "Level.h"

class Level_0: public Level{
	int cursor = 0; // Tracks which shape we are currently on
public:
    Level_0();
	Block *createBlock_from_seq(std::vector<char> &sequence) override;
};

#endif

#ifndef LEVEL_1
#define LEVEL_1

#include "Level.h"
#include <vector>

class Level_1: public Level{
	const int denum;
	const int I_prob;
	const int J_prob;
	const int L_prob;
	const int O_prob;
	const int S_prob;
	const int Z_prob;
	const int T_prob;
    public:
    Level_1();
    Block *createBlock() override;
};

#endif

#ifndef LEVEL_2
#define LEVEL_2

#include "Level.h"
#include <vector>

class Level_2: public Level{
	const int denum;
	const int I_prob;
	const int J_prob;
	const int L_prob;
	const int O_prob;
	const int S_prob;
	const int Z_prob;
	const int T_prob;
    public:
    Level_2();
    Block *createBlock() override;
};

#endif

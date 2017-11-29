#ifndef LEVEL_3
#define LEVEL_3

#include "Level.h"
#include <vector>

class Level_3: public Level{
	const int denum;
	const int I_prob;
	const int J_prob;
	const int L_prob;
	const int O_prob;
	const int S_prob;
	const int Z_prob;
	const int T_prob;
    public:
    Level_3();
    Block *createBlock() override;
};

#endif

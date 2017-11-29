#ifndef LEVEL_4
#define LEVEL_4

#include "Level.h"
#include <vector>

class Level_4: public Level{
	const int denum;
	const int I_prob;
	const int J_prob;
	const int L_prob;
	const int O_prob;
	const int S_prob;
	const int Z_prob;
	const int T_prob;
    public:
    Level_4();
    Block *createBlock() override;
};

#endif

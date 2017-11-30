#ifndef LEVEL_0
#define LEVEL_0

#include "Level.h"
#include <vector>

class Level_0: public Level{
    public:
    Level_0(std::vector<char> &sequence);
    Block *createBlock() override;
};

#endif

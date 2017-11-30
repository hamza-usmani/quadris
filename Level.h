#ifndef LEVEL 
#define LEVEL

#include <cstdlib>
#include <vector>
#include <memory>
#include "block.h"

// Abstract base class
class Level{
    int LevelDifficulty; //one of 0,1,2,3,4

    protected: //Ie subclasses can access, for style, move to private and provide setters/getters?
    std::vector<char> sequence;
    int index;
    bool gen_rand;


    Block *create_I_Block();
    Block *create_J_Block();
    Block *create_L_Block();
    Block *create_O_Block();
    Block *create_S_Block();
    Block *create_Z_Block();
    Block *create_T_Block();


    public:
    Level(int LevelDifficulty, std::vector<char> sequence, int index, bool gen_rand);
    virtual Block *createBlock() = 0;
    int getLevel();
    void randomOn();
    void randomOff(const std::vector<char> vec);
    ~Level();
};

#endif

#include "Level_2.h"
#include "block.h" 
#include <cstdlib>


/*
--- READ ME ---
Level randomness is determined in the following way:
The level is initialized with a denominator that represents the number of possible outcomes
Each block then is initialized with a probability that the corresponding block will be created
Since there is no end user interaction with this determintation, it is up to the designer to 
assert each block probability sums to denum. Failure to do so may result in undefined behaviour. 
*/

Level_2::Level_2(const int seed = 0): Level(2), seed(seed), denum(7), I_prob(1), J_prob(1), L_prob(1), O_prob(1), S_prob(1), Z_prob(1), T_prob(1) { }

// TODO: Possibility to throw exception on poorly built object? (Shouldn't be necessarys)

Block *Level_2::createBlock(){
    // srand(1); //TODO: Insert seed here
    int rand_num = rand() % denum + 1; // Chooses a random number between 1-denum (12 for this case)

    if (rand_num <= I_prob){ 
        return create_I_Block();
    } else if (rand_num <= I_prob + J_prob){ 
        return create_J_Block();
    } else if (rand_num <= I_prob + J_prob + L_prob){ 
        return create_L_Block();
    } else if (rand_num <= I_prob + J_prob + L_prob + O_prob){ 
        return create_O_Block();
    } else if (rand_num <= I_prob + J_prob + L_prob + O_prob + S_prob){ 
        return create_S_Block();
    } else if (rand_num <= I_prob + J_prob + L_prob + O_prob + S_prob + Z_prob){
        return create_Z_Block();
    } else{
        return create_T_Block();
    }
}

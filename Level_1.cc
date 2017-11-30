#include "Level_1.h"
#include "block.h" 
#include <cstdlib>
#include <iostream>

/*
--- READ ME ---
Level randomness is determined in the following way:
The level is initialized with a denominator that represents the number of possible outcomes
Each block then is initialized with a probability that the corresponding block will be created
Since there is no end user interaction with this determintation, it is up to the designer to 
assert each block probability sums to denum. Failure to do so may result in undefined behaviour. 
*/

Level_1::Level_1(): Level(1, std::vector<char>(),0, true), denum(12), I_prob(2), J_prob(2), L_prob(2), O_prob(2), S_prob(1), Z_prob(1), T_prob(2) { }

Block *Level_1::createBlock(){
    if (gen_rand){
        int rand_num = rand() % denum + 1; // Chooses a random number between 1-denum (12 for this case)
        //std::cout<<"rand_num is: "<<rand_num<<std::endl;
        if (rand_num <= I_prob){ // <= 2 (2/12)
            return create_I_Block();
        } else if (rand_num <= I_prob + J_prob){ // beween 3 and 4 (2/12)
           return create_J_Block();
        } else if (rand_num <= I_prob + J_prob + L_prob){ // beween 5 and 6 (2/12)
            return create_L_Block();
        } else if (rand_num <= I_prob + J_prob + L_prob + O_prob){ // beween 7 and 8 (2/12)
            return create_O_Block();
        } else if (rand_num <= I_prob + J_prob + L_prob + O_prob + S_prob){ // beween 9 and 9 (1/12)
            return create_S_Block();
        } else if (rand_num <= I_prob + J_prob + L_prob + O_prob + S_prob + Z_prob){ // beween 10 and 10 (1/12)
            return create_Z_Block();
        } else{
            return create_T_Block(); //between 11 and 12 (2/12)
        }
    }else{
        if (index > sequence.size() - 1) return nullptr;
    
        char curChar = sequence.at(index);
        index++;

        if (index == sequence.size()) index = 0;
    
        if      (curChar == 'i' || curChar == 'I') return create_I_Block();
        else if (curChar == 'j' || curChar == 'J') return create_J_Block();
        else if (curChar == 'l' || curChar == 'L') return create_L_Block();
        else if (curChar == 'o' || curChar == 'O') return create_O_Block();
        else if (curChar == 's' || curChar == 'S') return create_S_Block();
        else if (curChar == 'z' || curChar == 'Z') return create_Z_Block();
        else return create_T_Block();
    }
}
    

#include "Level_0.h"
#include "block.h" 
#include "iblock.h" 
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

Level_0::Level_0(){
    this->LevelDifficulty = 0;
}

Block *Level_0::createBlock_from_seq(std::vector<char> &sequence){
	char shape = sequence[cursor];
	this->cursor++;

	Block *my_block = new IBlock{0}; // TODO: Safe pointer Ie. auto my_block = std::make_shared<IBlock>(0);
	return my_block;
	// ^^ this follows factory example in tutorial
/*
	switch(shape){
		case I:
			Iblock my_block(0);
			return my_block;
		case J:
			Jblock my_block(0);
			return my_block;
		case L:
			Lblock my_block(0);
			return my_block;
		case O:
			Oblock my_block(0);
			return my_block;
		case S:
			Sblock my_block(0);
			return my_block;
		case Z:
			Zblock my_block(0);
			return my_block;
		case T:
			Tblock my_block(0);
			return my_block;

	}
*/

}

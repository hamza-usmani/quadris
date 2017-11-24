#include "Level_0.h"
#include "block.h" 
#include "iblock.h" 
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include <memory>

Level_0::Level_0(){
    this->LevelDifficulty = 0;
}

Block *Level_0::createBlock_from_seq(std::vector<char> &sequence){
	char shape = sequence[cursor];
	this->cursor++;

	//Block *my_block = new IBlock{0}; 
	// ^^ this follows factory example in tutorial

	switch(shape){
		case I:{
			auto my_block = std::make_shared<IBlock>(0);
			return my_block.get();
		}case J:{
			auto my_block = std::make_shared<JBlock>(0);
			return my_block.get();
		}case L:{
			auto my_block = std::make_shared<LBlock>(0);
			return my_block.get();
		}case O:{
			auto my_block = std::make_shared<OBlock>(0);
			return my_block.get();
		}case S:{
			auto my_block = std::make_shared<SBlock>(0);
			return my_block.get();
		}case Z:{
			auto my_block = std::make_shared<ZBlock>(0);
			return my_block.get();
		}case T:{
			auto my_block = std::make_shared<TBlock>(0);
			return my_block.get();
		}
	}
}

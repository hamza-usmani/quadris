#include "board.h"
#include "block.h"
#include <iostream>

Board::Board(int width, int height, int curLevel): width(width), height(height), curLevel(curLevel), score(0), highscore(0){
   TextDisplay *tmpDisplay = new TextDisplay(width, height);
   td = tmpDisplay;
    
    for (int j=0; j<height; j++){
        std::vector<Cell> tmp;
        for (int i=0; i<width; i++){
            Cell tmpCell(i,j);
            tmpCell.attach(td);
            tmp.emplace_back(tmpCell);
        }
        grid.emplace_back(tmp);
    }
}

bool Board::isLastRowFull(){
    return grid.at(height-1).empty();
}

//this will remove the last row in the grid
void Board::removeLine(){
    
}

//this will add a Block object to the grid by modifying required cells
bool Board::addBlock(Block *b){
    for (auto i: b->getPositions()){
        grid.at(i.y).at(i.x).setState(b->getBlockChar());
    }
    return true;
}

//this will simply erase a Block objects positions from grid
void Board::eraseBlock(Block *b){
    
}

std::ostream &operator<<(std::ostream &out, const Board &b){
    out<<"Level: "<<b.curLevel<<std::endl;
    out<<"Score: "<<b.score<<std::endl;
    out<<"Hi Score: "<<b.highscore<<std::endl;
    out<< (*b.td);
    return out;
}

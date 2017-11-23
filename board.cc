#include "board.h"

Board::Board(int width, int height): width(width), height(height){
   auto tmpDisplay =  std::make_shared<TextDisplay>(width, height);
   td = tmpDisplay;
    
    for (int j=0; j<height; j++){
        std::vector<Cell> tmp;
        for (int i=0; i<width; i++){
            Cell tmpCell(i,j);
            tmpCell.attach(td.get());
            tmp.emplace_back(tmpCell);
        }
        grid.emplace_back(tmp);
    }
}

bool Board::isLastRowFull(){
    return grid.at(height-1).empty();
}

void Board::removeLine(){
    //this will remove the last row in the grid
}

bool Board::addBlock(Block &){
    //this will add a Block object to the grid by modifying required cells
    return false; //temp
}
void Board::eraseBlock(Block &){
    //this will simply erase a Block objects positions from grid
}

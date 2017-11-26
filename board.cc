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
    for (auto i: grid.at(height-1)){
        if (i.getState() == State::NONE) return false;
    }
    return true;
}

//this will remove the last row in the grid
void Board::removeLine(){
    for (int i = height-1; i>=0; i--){
        for (int j=0; j< width; j++){
            if (i == 0){
                grid.at(i).at(j) = Cell(i,j);
            }
            else grid.at(i).at(j) = grid.at(i-1).at(j);
        }
    }
}

//this will add a Block object to the grid by modifying required cells
bool Board::addBlock(Block *b){
    for (auto i: b->getPositions()){
        grid.at(i.y).at(i.x).setBlock(b);
    }
    return true;
}

//this will simply erase a Block objects positions from grid
void Board::eraseBlock(Block *b){
    for (auto i: b->getPositions()){
        grid.at(i.y).at(i.x).clearCell();
    }
}

//drop a block to the bottom
void Board::dropBlock(Block *b){
    int curY = b->getLeftCorner().y;
    
    while (curY < height - 1){
        bool found = false;
        
        for (auto i: b->getPositions()){
            if (grid.at(i.y+1).at(i.x).getCur() != b && grid.at(i.y+1).at(i.x).getState() != State::NONE){
                found = true;
                break;
            }
        }
        if (found) break;
        this->eraseBlock(b);
        b->moveDown(1);
        this->addBlock(b);
    
        curY++;
    }
}

void Board::moveBlockHorizontally(Block *b, int x){ //if no number recieved, ie "right" pass in x = 1
    int curY = b->getLeftCorner().y;
    
    //moving right
    if (x > 0){
        int curX = b->getLeftCorner().x + b->getWidth();
        int newX = curX + x;
        if (newX > width) {
            return;
        }
        bool found = false;
        
        for (curX; curX <= width; curX++){
            if (curX < newX){
                 if (grid.at(curY).at(curX).getState() != State::NONE){
                     found = true;
                     break;
                 }
            }
            else break;
            if (found) break;
        }
        this->eraseBlock(b);
        b->moveHorizontally(x);
        this->addBlock(b);
    }
    
    //moving left
    else if (x < 0){
        int curX = b->getLeftCorner().x;
        int newX = curX + x;
        if (newX < 0) {
            return;
        }
        //this->eraseBlock(b);
        bool found = false;
        
        for (curX; curX >= 0; curX--){
            if (curX > newX){
                if (grid.at(curY).at(curX).getState() != State::NONE ){
                    found = true;
                    break;
                }
            }
            else break;
            if (found) break;
        }
        this->eraseBlock(b);
        b->moveHorizontally(x);
        this->addBlock(b);
    }
    
}


std::ostream &operator<<(std::ostream &out, const Board &b){
    out<<"Level: "<<b.curLevel<<std::endl;
    out<<"Score: "<<b.score<<std::endl;
    out<<"Hi Score: "<<b.highscore<<std::endl;
    out<< (*b.td);
    return out;
}

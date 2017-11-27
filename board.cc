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
    for (auto i: grid.back()){
        if (i.getState() != State::NONE && i.getCur() != nullptr){
            Block *b = i.getCur();
            //b->
        }
    }
    
}

    /*
    grid.popback();
    auto it = grid.begin();
    
    std::vector<Cell> tmp;
    for (int i=0; i<width; i++){
        Cell tmpCell(i,0);
        tmpCell.attach(td);
        tmp.emplace_back(tmpCell);
    }
    it = grid.insert(it, tmp);*/



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

//will move a block down
void Board::moveDown(Block *b, int y){ //if no number recieved, ie "down" pass in y = 1
    int curY = b->getLeftCorner().y;
    int newY = curY + y;
    if (newY >= height) newY = height - 1; //return;
    
    while (curY < height - 1){
        if (curY == newY) break;
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

//will move a block left or right
void Board::moveBlockHorizontally(Block *b, int x){ //if no number recieved, ie "right" pass in x = 1
    //moving right
    if (x > 0){
        int curX = b->getLeftCorner().x + b->getWidth() - 1;
        int newX = curX + x;
        if (newX >= width) newX = width - 1;//return;

        while (curX < width - 1){
            if (curX == newX) break;
            bool found = false;
            for (auto i: b->getPositions()){
                if (grid.at(i.y).at(i.x+1).getCur() != b && grid.at(i.y).at(i.x+1).getState() != State::NONE){
                    found = true;
                    break;
                }
            }
            if (found) break;
            this->eraseBlock(b);
            b->moveHorizontally(1);
            this->addBlock(b);
            curX++;
        }
    }
    //moving left
    else if (x < 0){
        int curX = b->getLeftCorner().x;
        int newX = curX + x;
        if (newX < 0) newX = 0; //return;
        
        while (curX > 0){
            if (curX == newX) break;
            bool found = false;
            for (auto i: b->getPositions()){
                if (grid.at(i.y).at(i.x-1).getCur() != b && grid.at(i.y).at(i.x-1).getState() != State::NONE){
                    found = true;
                    break;
                }
            }
            if (found) break;
            this->eraseBlock(b);
            b->moveHorizontally(-1);
            this->addBlock(b);
            curX--;
        }
    }
}

//rotate clockwise
void Board::rotateClockwise(Block *b){
    this->eraseBlock(b);
    b->rotateClockwise();
    
    for (auto i: b->getPositions()){
        if (grid.at(i.y).at(i.x).getState() != State::NONE){
            b->rotateCounterclockwise();
            break;
        }
    }
    this->addBlock(b);
}

//rotate counterclockwise
void Board::rotateCounterclockwise(Block *b){
    this->eraseBlock(b);
    b->rotateCounterclockwise();
    
    for (auto i: b->getPositions()){
        if (grid.at(i.y).at(i.x).getState() != State::NONE){
            b->rotateClockwise();
            break;
        }
    }
    this->addBlock(b);
}

//drop a block to the bottom, ie. place it
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


std::ostream &operator<<(std::ostream &out, const Board &b){
    out<<"Level: "<<b.curLevel<<std::endl;
    out<<"Score: "<<b.score<<std::endl;
    out<<"Hi Score: "<<b.highscore<<std::endl;
    out<< (*b.td);
    return out;
}

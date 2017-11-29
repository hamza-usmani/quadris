#include "board.h"
#include "block.h"
#include <iostream>

Board::Board(int width, int height, int curLevel): width(width), height(height), curLevel(curLevel), score(0), highscore(0){
   TextDisplay *tmpDisplay = new TextDisplay(width, height);
   td = tmpDisplay;
   next = nullptr;
    
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

bool Board::isRowFull(int row){
    for (auto &i: grid.at(row)){
        if (i.getState() == State::NONE) return false;
    }
    return true;
}


//this will remove the row in the grid
void Board::removeLine(int row){
    std::vector<Block *> emptyBlocks;
    
    for (auto &i: grid.at(row)){
        if (i.getState() != State::NONE && i.getCur() != nullptr){
            
            Block *b = i.getCur();
            b->removePosition(i.getPosition());
            
            if (b->getPositions().empty()){
                emptyBlocks.emplace_back(b);
            }
        }
        i.clearCell();
    }
    
    for (int i=row; i > 0; i--){
        for (int j=0; j<width; j++){
            Block *cur = grid.at(i-1).at(j).getCur();
            grid.at(i).at(j).clearCell();
            if (cur) {
                grid.at(i).at(j).setBlock(cur);
            }
        }
    }
    
    //scoring for completely removed blocks
    for (auto &i: emptyBlocks){
        score += ((i->getLevelCreated() + 1) * (i->getLevelCreated() + 1));
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
void Board::rotateClockwise(Block *b, int repeat){
    while (repeat > 0){
        this->eraseBlock(b);
        b->rotateClockwise();
        
        for (auto i: b->getPositions()){
            if (grid.at(i.y).at(i.x).getState() != State::NONE){
                b->rotateCounterclockwise();
                break;
            }
        }
        this->addBlock(b);
        repeat--;
    }
}

//rotate counterclockwise
void Board::rotateCounterclockwise(Block *b, int repeat){
    while (repeat > 0){
        this->eraseBlock(b);
        b->rotateCounterclockwise();
        
        for (auto i: b->getPositions()){
            if (grid.at(i.y).at(i.x).getState() != State::NONE){
                b->rotateClockwise();
                break;
            }
        }
        this->addBlock(b);
        repeat--;
    }
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
    
    //check if any lines are full and increase counter for each block
    int linesCleared = 0;
    
    for (int i=0; i<height; i++){
        while(this->isRowFull(i)){
            linesCleared++;
            this->removeLine(i);
        }
        for (int j=0; j<width; j++){
            if (grid.at(i).at(j).getCur() != nullptr){
                grid.at(i).at(j).getCur()->increaseCount();
            }
        }
    }
    //scoring for number of lines removed
    if (linesCleared > 0) score+= ((curLevel + linesCleared) * (curLevel + linesCleared));
}

void Board::setNext(Block *b){
    next = b;
    td->setNext(next);
}

void Board::levelUp(int n){
    curLevel+= n;
}
void Board::LevelDown(int n){
    curLevel-= n;
}

std::ostream &operator<<(std::ostream &out, const Board &b){
    out<<"Level: "<<b.curLevel<<std::endl;
    out<<"Score: "<<b.score<<std::endl;
    out<<"Hi Score: "<<b.highscore<<std::endl;
    out<< (*b.td);
    return out;
}

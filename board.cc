#include "board.h"
#include "block.h"
#include <iostream>
#include "global.h"
#include "blankblock.h"
#include <set>

Board::Board(int width, int height, int curLevel): width(width), height(height), curLevel(curLevel), score(0){
   TextDisplay *tmpDisplay = new TextDisplay(width, height);
   td = tmpDisplay;
   next = nullptr;
    
    for (int j=0; j<this->height; j++){
        std::vector<Cell> tmp;
        for (int i=0; i<this->width; i++){
            Cell tmpCell(i,j);
            tmpCell.attach(td);
            tmp.emplace_back(tmpCell);
        }
        this->grid.emplace_back(tmp);
    }
    gd = nullptr;
}

void Board::setGraphics(GraphicsDisplay *setTo){
    this->gd = setTo;
    if (this->gd){
        for (auto &i: grid){
            for (auto &j: i){
                j.attach(this->gd);
                gd->notify(j);
            }
        }
    }
}

bool Board::isRowFull(int row){
    for (auto &i: this->grid.at(row)){
        if (i.getState() == State::NONE) return false;
    }
    return true;
}

bool Board::canPlace(Block *b){
    for (auto i: b->getPositions()){
        if (this->grid.at(i.y).at(i.x).getCur() != b && this->grid.at(i.y).at(i.x).getState() != State::NONE) return false;
    }
    return true;
}


//this will remove the row in the grid
void Board::removeLine(int row){
    std::vector<Block *> emptyBlocks;
    
    for (auto &i: this->grid.at(row)){
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
            Block *cur = this->grid.at(i-1).at(j).getCur();
            this->grid.at(i).at(j).clearCell();
            if (cur) {
                this->grid.at(i).at(j).setBlock(cur);
            }
        }
    }
    
    //scoring for completely removed blocks
    for (auto &i: emptyBlocks){
        this->score += ((i->getLevelCreated() + 1) * (i->getLevelCreated() + 1));
        curscore = this->score;
    }
}


//this will add a Block object to the grid by modifying required cells
void Board::addBlock(Block *b){
    for (auto i: b->getPositions()){
        this->grid.at(i.y).at(i.x).setBlock(b);
    }
}


//this will simply erase a Block objects positions from grid
void Board::eraseBlock(Block *b){
    for (auto i: b->getPositions()){
        this->grid.at(i.y).at(i.x).clearCell();
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
            if (this->grid.at(i.y+1).at(i.x).getCur() != b && this->grid.at(i.y+1).at(i.x).getState() != State::NONE){
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
                if (this->grid.at(i.y).at(i.x+1).getCur() != b && this->grid.at(i.y).at(i.x+1).getState() != State::NONE){
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
                if (this->grid.at(i.y).at(i.x-1).getCur() != b && this->grid.at(i.y).at(i.x-1).getState() != State::NONE){
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
    
    if (b->getIsHeavy()){
        moveDown(b, 1);
    }
}

//rotate clockwise
void Board::rotateClockwise(Block *b, int repeat){
    while (repeat > 0){
        this->eraseBlock(b);
        b->rotateClockwise();
        
        for (auto i: b->getPositions()){
            if (this->grid.at(i.y).at(i.x).getState() != State::NONE){
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
            if (this->grid.at(i.y).at(i.x).getState() != State::NONE){
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
            if (this->grid.at(i.y+1).at(i.x).getCur() != b && this->grid.at(i.y+1).at(i.x).getState() != State::NONE){
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
            if (this->grid.at(i).at(j).getCur() != nullptr){
                this->grid.at(i).at(j).getCur()->increaseCount();
            }
        }
    }
    //scoring for number of lines removed
    if (linesCleared > 0) {
        this->score+= ((curLevel + linesCleared) * (curLevel + linesCleared));
        curscore = this->score;
        totalLinesCleared += linesCleared;
    }
    if (this->score > highscore) highscore = this->score;
}

void Board::addBlankBlock(){
    BlankBlock *tmp = new BlankBlock(curLevel);
    tmp->moveHorizontally(this->width/2);
    this->dropBlock(tmp);
}

void Board::setNext(Block *b){
    this->next = b;
    if (td) td->setNext(next);
    if (gd) gd->setNext(next);
}

void Board::levelUp(int n){
    this->curLevel+= n;
    default_level = this->curLevel;
}
void Board::LevelDown(int n){
    this->curLevel-= n;
    default_level = this->curLevel;
}

Board::~Board(){ }

void Board::deleteDisplay(){
    std::set<Block *> toClear;
    
    for (auto i: grid){
        for (auto j: i){
            if (j.getCur()) toClear.insert(j.getCur());
        }
    }
    
    for (auto i: toClear){
        delete i;
    }
    delete next;
    delete td;
    delete gd;
}

std::ostream &operator<<(std::ostream &out, const Board &b){
    out<< (*b.td);
    return out;
}

std::vector<Pos> Board::getHint(Block *b){

    std::vector<Pos> returnVect = b->getPositions();
    std::vector<Pos> tmp = b->getPositions();
    std::vector<Pos> bestPos;
    
    int maxCleared = 0;
    int maxY = 0;
    
    for (int i=0; i<4; i++){
      b->rotateClockwise();
      returnVect = b->getPositions();
      tmp = b->getPositions();
    
    for (int j = 0; j < this->width - b->getWidth(); j++){
        for (auto &k: tmp){ //moving right
            k.x += j;
        }
        
        int linesCleared = 0;
        int curY = b->getLeftCorner().y;
        
        //finding the lowest point we can go, dropping it
        while (curY < height - 1){
            bool found = false;
            for (auto i: tmp){
                if (this->grid.at(i.y+1).at(i.x).getCur() != b && this->grid.at(i.y+1).at(i.x).getState() != State::NONE && this->grid.at(i.y+1).at(i.x).getState() != State::Hint){
                    found = true;
                    break;
                }
            }
            if (found) break;
            
            for (auto i:tmp){
                this->grid.at(i.y).at(i.x).clearCell();
            }
            
            for (auto &i:tmp){
                i.y+=1;
            }
            
            curY++;
        }
        
        for (auto i:tmp){
            this->grid.at(i.y).at(i.x).setHint();
        }
        
        for (int k= height-1; k>2; k--){ //checking all rows if full
            if (isRowFull(k)) linesCleared++;
        }
        
        if (linesCleared > maxCleared) { //checking if more lines cleared
            maxCleared = linesCleared;
            bestPos.clear();
            bestPos = tmp;
        }
        else if (linesCleared == maxCleared && curY > maxY){
            maxY = curY;
            bestPos.clear();
            bestPos = tmp;
        }
        
        for (auto k: tmp){ //setting cells back to NONE
            if (this->grid.at(k.y).at(k.x).getState() == State::Hint) this->grid.at(k.y).at(k.x).clearCell();
        }
        
        tmp = returnVect; //reset y coordinates
    }
    
    }
    for (auto i: bestPos){
        grid.at(i.y).at(i.x).showHint();
    }
    return bestPos;
}

void Board::clearHint(std::vector<Pos> hint){
    for (auto i: hint) this->grid.at(i.y).at(i.x).clearCell();
}


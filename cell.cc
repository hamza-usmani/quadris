#include "cell.h"
#include "block.h"

Cell::Cell(int width, int height){
    this->position = Pos{width, height};
    this->cellState = State::NONE;
    this->cur = nullptr;
}

Pos Cell::getPosition(){
    return this->position;
}

State Cell::getState(){
    return this->cellState;
}

void Cell::clearCell(){
    this->cellState = State::NONE;
    this->cur = nullptr;
    this->notifyObservers();
}

void Cell::setBlock(Block *curBlock){
    char blockChar = curBlock->getBlockChar();
    if (blockChar == 'i') this->cellState = State::I;
    else if (blockChar == 'j') this->cellState = State::J;
    else if (blockChar == 'l') this->cellState = State::L;
    else if (blockChar == 'o') this->cellState = State::O;
    else if (blockChar == 's') this->cellState = State::S;
    else if (blockChar == 'z') this->cellState = State::Z;
    else if (blockChar == 't') this->cellState = State::T;
    else if (blockChar == '*') this->cellState = State::Star;
    this->cur = curBlock;
    this->notifyObservers();
}

void Cell::setHint(){
    this->cellState = State::Hint;
}

void Cell::showHint(){
    this->cellState = State::Hint;
    this->notifyObservers();
}


Block *Cell::getCur(){
    return this->cur;
}

void Cell::attach(Observer *o) {
    observers.emplace_back(o);
}

void Cell::notifyObservers() {
    for (auto &ob : observers){
        ob->notify(*this);
    }
}

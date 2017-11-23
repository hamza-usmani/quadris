#include "cell.h"

Cell::Cell(){
    this->cellState = State::NONE;
    this->cur = nullptr;
}

State Cell::getState(){
    return this->cellState;
}

Block *Cell::getCur(){
    return this->cur;
}

void Cell::setCur(Block *changeTo){
    this->cur = changeTo;
}

void Cell::attach(Observer *o) {
    observers.emplace_back(o);
}

void Cell::notifyObservers() {
    for (auto &ob : observers){
        ob->notify(*this);
    }
}

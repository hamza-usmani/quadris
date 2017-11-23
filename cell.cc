#include "cell.h"

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

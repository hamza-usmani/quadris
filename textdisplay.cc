#include <iostream>
#include "textdisplay.h"
#include "cell.h"

TextDisplay::TextDisplay(int width, int height): width(width), height(height) {
    for (int i=0; i<height; i++){
        std::vector<char> tmp(width, ' ');
        display.emplace_back(tmp);
    }
}

void TextDisplay::notify(Cell &whoFrom){
    int x = whoFrom.getPosition().x;
    int y = whoFrom.getPosition().y;
    
    if (whoFrom.getState() == State::NONE) display.at(y).at(x) = ' ';
    else if (whoFrom.getState() == State::I) display.at(y).at(x) = 'I';
    else if (whoFrom.getState() == State::J) display.at(y).at(x) = 'J';
    else if (whoFrom.getState() == State::L) display.at(y).at(x) = 'L';
    else if (whoFrom.getState() == State::O) display.at(y).at(x) = 'O';
    else if (whoFrom.getState() == State::S) display.at(y).at(x) = 'S';
    else if (whoFrom.getState() == State::Z) display.at(y).at(x) = 'Z';
    else if (whoFrom.getState() == State::T) display.at(y).at(x) = 'T';
}


std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
    for (auto i: td.display){
        for (auto j: i){
            out<<j;
        }
        out<<std::endl;
    }
    return out;
}

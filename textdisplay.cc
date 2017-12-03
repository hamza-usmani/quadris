#include <iostream>
#include "textdisplay.h"
#include "cell.h"
#include "global.h"

TextDisplay::TextDisplay(int width, int height): width(width), height(height), next(nullptr) {
    for (int i=0; i<height; i++){
        std::vector<char> tmp(width, ' ');
        display.emplace_back(tmp);
    }
}

void TextDisplay::setNext(Block *b){
    next = b;
}

void TextDisplay::printNext(std::ostream &out){
    if (!next) return;
    std::vector<std::vector<State>> nextBlock = next->printBlock();
    for (auto i: nextBlock){
        for (auto j: i){
            if (j == State::NONE) out<< ' ';
            else if (j== State::I) out<<'I';
            else if (j == State::J) out<< 'J';
            else if (j == State::L) out<< 'L';
            else if (j == State::O) out<< 'O';
            else if (j == State::S) out<< 'S';
            else if (j == State::Z) out<< 'Z';
            else if (j == State::T) out<< 'T';
        }
        out<<std::endl;
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
    else if (whoFrom.getState() == State::Star) display.at(y).at(x) = '*';
    else if (whoFrom.getState() == State::Hint) display.at(y).at(x) = '?';
}


std::ostream &operator<<(std::ostream &out, TextDisplay &td){
    out<<"Level: "<<default_level<<std::endl;
    out<<"Score: "<<curscore<<std::endl;
    out<<"Hi Score: "<<highscore<<std::endl;
    
    for (int i=0; i<td.width; i++) out<<"-";
    out<<std::endl;
    for (auto i: td.display){
        for (auto j: i){
            out<<j;
        }
        out<<std::endl;
    }
    for (int i=0; i<td.width; i++) out<<"-";
    out<<std::endl<<"Next:"<<std::endl;
    td.printNext(out);
    out<<std::endl;
    return out;
}

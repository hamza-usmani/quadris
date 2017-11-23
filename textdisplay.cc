#include "textdisplay.h"
#include <iostream>

TextDisplay::TextDisplay(int width, int height): width(width), height(height) {
    for (int i=0; i<height; i++){
        std::vector<char> tmp(width, ' ');
        display.emplace_back(tmp);
    }
}

void TextDisplay::notify(Cell &whoFrom){
   //will update
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

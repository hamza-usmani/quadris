#ifndef textdisplay_h
#define textdisplay_h

#include <vector>
#include "observer.h"
#include "block.h"

class Cell;

class TextDisplay: public Observer {
    std::vector<std::vector<char>> display;
    int width;
    int height;
    Block *next;
    
    void printNext(std::ostream &out);
    
    public:
    TextDisplay(int width, int height);
    void setNext(Block *b);
    void notify(Cell &whoFrom) override;
    
    friend std::ostream &operator<<(std::ostream &out, TextDisplay &td);
};

#endif

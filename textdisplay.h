#ifndef textdisplay_h
#define textdisplay_h

#include <vector>
#include "observer.h"

class Cell;

class TextDisplay: public Observer {
    std::vector<std::vector<char>> display;
    int width;
    int height;
    public:
    TextDisplay(int width, int height);
    void notify(Cell &whoFrom) override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

#ifndef board_h
#define board_h

#include <vector>
#include "cell.h"
#include "textdisplay.h"
class Block;

class Board{
    std::vector<std::vector<Cell>> grid;
    int width;
    int height;
    TextDisplay *td = nullptr;
    public:
    Board(int width, int height);
    bool isLastRowFull();
    void removeLine();
    //void dropBlock(); I will deal with this once the transformations are implemented
    bool addBlock(Block &);
    void eraseBlock(Block &);
};

#endif

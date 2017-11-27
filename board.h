#ifndef board_h
#define board_h

#include <memory>
#include <vector>
#include "cell.h"
#include "textdisplay.h"
class Block;

class Board{
    
    std::vector<std::vector<Cell>> grid;
    int width;
    int height;
    int curLevel;
    int score;
    int highscore;
    TextDisplay *td;
    //vector<char> nextBlock;
    
    public:
    Board(int width, int height, int curLevel);
    bool isLastRowFull();
    
    void removeLine();
    bool addBlock(Block *b);
    void eraseBlock(Block *b);
    
    void moveDown(Block *b, int n);
    void moveBlockHorizontally(Block *b, int x);
    void rotateClockwise(Block *b);
    void rotateCounterclockwise(Block *b);
    void dropBlock(Block *b);
    
    
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

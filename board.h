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
    Block *next;
    
    public:
    Board(int width, int height, int curLevel);
    
    bool isRowFull(int row);
    bool canPlace(Block *b);
    void removeLine(int row);
    void addBlock(Block *b);
    void eraseBlock(Block *b);
    void moveDown(Block *b, int n);
    void moveBlockHorizontally(Block *b, int x);
    void rotateClockwise(Block *b, int repeat);
    void rotateCounterclockwise(Block *b, int repeat);
    void dropBlock(Block *b);
    void setNext(Block *b);
    void levelUp(int n);
    void LevelDown(int n);
    
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

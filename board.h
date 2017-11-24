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
    std::shared_ptr<TextDisplay> td;
    //vector<char> nextBlock;
    
    public:
    Board(int width, int height, int curLevel);
    bool isLastRowFull();
    void removeLine();
    //void dropBlock(); I will deal with this once the transformations are implemented
    bool addBlock(Block &);
    void eraseBlock(Block &);
    
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif

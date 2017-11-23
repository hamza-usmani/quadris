#include <iostream>
#include <string>
#include "board.h"

using namespace std;

const int width = 11;
const int height = 18;

int main(int argc, const char * argv[]) {
    
    Board mainBoard(width, height);
    //level *l = new LevelZero;
    //Block *current = l->createBlock();
    //Blocks *next;
    int score, highscore;
    string cmd;
    
    while(true){
        //next = l->createBlock();
        //mainBoard->addBlock(&cur);
        
        cin>>cmd;
        
        if (cmd == "left") { }
        else if (cmd == "right") { }
        else if (cmd == "down") { }
        else if (cmd == "clockwise") { }
        else if (cmd == "counterclockwise") { }
        
        //cur = next;
    }
    
    return 0;
}

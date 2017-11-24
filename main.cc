#include <iostream>
#include <memory>
#include <string>
#include "board.h"
#include "Level.h"
#include "Level_0.h"

using namespace std;

//use the flags below combined with cout statements in code to help track issuesa
const int LEVEL_DIAGNOSTIC = 0;
// add more flags here

const int width = 11;
const int height = 18;


int main(int argc, const char * argv[]) {
    
    //currently mainBoard is initiated with fixed level 0
    Board mainBoard(width, height, 0);
    auto l = make_shared<Level>();
   
    //lets default to level 0 for now
    Level_0 curLevel;
    *l = curLevel;
    
    //Block *current = l->createBlock();
    //Blocks *next;

    cout<<mainBoard;
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

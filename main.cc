#include <iostream>
#include <memory>
#include <string>
#include "board.h"
#include "Level.h"
#include "Level_0.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Level_4.h"

using namespace std;

//temp Flags
const int LEVEL_DIAGNOSTIC = 0;

const int width = 11;
const int height = 18;


int main(int argc, const char * argv[]) {
    
    //currently mainBoard is initiated with fixed level 0
    Board mainBoard(width, height, 0);
    Level *l;
   
    //lets default to level 0 for now, testing with a fixed vector
    vector<char> tmp;
    tmp.emplace_back('z');
    tmp.emplace_back('i');
    tmp.emplace_back('t');
    l = new Level_0(tmp);
    
    Block *current = l->createBlock();
    Block *next;

    cout<<mainBoard;
    string cmd;
    
    while(current){
        mainBoard.addBlock(current);
        cout<<mainBoard;
        next = l->createBlock();
        
        cin>>cmd;
        if (cmd == "left") { }
        else if (cmd == "right") { }
        else if (cmd == "down") { }
        else if (cmd == "clockwise") { }
        else if (cmd == "counterclockwise") { }
        else if (cmd == "drop") {
            mainBoard.dropBlock(current);
            cout<<mainBoard;
        }
        else if (cmd == "c") { }
        
        current = next;
    }
    
    return 0;
}

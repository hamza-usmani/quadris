#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include "board.h"
#include "Level.h"
#include "Level_0.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Level_4.h"
#include "commands.h"

using namespace std;

const int width = 11;
const int height = 18;

int main(int argc, const char * argv[]) {
    
    //currently mainBoard is initiated with fixed level 0
    Board mainBoard(width, height, 0);
    Level *l;
   
    //lets default to level 0 for now
    vector<char> sequence_txt_vector;
    build_vector_from_file(sequence_txt_vector, "test.txt");
    
    l = new Level_0(sequence_txt_vector);
    
    Block *current = l->createBlock();
    Block *next = l->createBlock();

    cout<<mainBoard;
    string cmd;
    
    while(true){
        if (!current){
            cout<<mainBoard;
            break;
        }
        mainBoard.addBlock(current);
        cout<<mainBoard;
        
        cin>>cmd;
        if (cmd == "left") {
            mainBoard.moveBlockHorizontally(current, -1);
        }
        else if (cmd == "right") {
            mainBoard.moveBlockHorizontally(current, 1);
        }
        else if (cmd == "down") {
            mainBoard.moveDown(current, 1);
        }
        else if (cmd == "clockwise") { }
        else if (cmd == "counterclockwise") { }
        else if (cmd == "drop") {
            next = l->createBlock();
            mainBoard.dropBlock(current);
            current = next;
        }
    }
    
    return 0;
}

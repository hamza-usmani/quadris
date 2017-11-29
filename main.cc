#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
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
    
    while(true){
        mainBoard.setNext(next);
        
        if (!current){
            cout<<mainBoard;
            break;
        }
        mainBoard.addBlock(current);
        cout<<mainBoard;
        
        string cmd;
        int multiplier = 1;
        readCommand(cin, cmd, multiplier);
        
        if (cmd == "left") {
            mainBoard.moveBlockHorizontally(current, -multiplier);
        }
        else if (cmd == "right") {
            mainBoard.moveBlockHorizontally(current, multiplier);
        }
        else if (cmd == "down") {
            mainBoard.moveDown(current, multiplier);
        }
        else if (cmd == "clockwise") {
            mainBoard.rotateClockwise(current, multiplier);
        }
        else if (cmd == "counterclockwise") {
             mainBoard.rotateCounterclockwise(current, multiplier);
        }
        else if (cmd == "drop") {
            for (int i=0; i< multiplier; i++){
                if (!current) break;
                mainBoard.dropBlock(current);
                current = next;
                next = l->createBlock();
            }
        }
        else if (cmd == "error"){
            cout<<"Invalid Command"<<std::endl;
        }
        cout<<std::endl;
    }
    
    return 0;
}

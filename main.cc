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

using namespace std;

//temp Flags

const int width = 11;
const int height = 18;

void build_vector_from_file(vector<char> &my_vect, string f_name){
    ifstream my_file (f_name);
    if (my_file.is_open()){
        char x;
        while (my_file >> x){
            my_vect.emplace_back(x);
        }
        my_file.close();
    }
}

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
        else if (cmd == "down") { }
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

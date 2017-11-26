#include <iostream>
#include <memory>
#include <string>
#include <fstream>
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

// Builds a vector from a given file
// TODO: Secure proper input
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
    build_vector_from_file(sequence_txt_vector, "sequence.txt");

    l = new Level_0(sequence_txt_vector);
    
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

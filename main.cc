#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "board.h"
#include "commands.h"


int main(int argc, const char * argv[]) {
	
    Level *l;
   
    //lets default to level 0 for now, and file "test.txt"
    int default_level = 0;
    string file = "sequence.txt";
    /*
	----- COMMAND-LINE ARGUMENT HANDLING -----
	Goes through all supplied command line 
	arguments ignoring any irrelevant args
	TODO: Assert numerics supplied; we need to 
	talk about error handling next time we meet
	*/
	for (int i = 1; i<argc; ++i){ //going through all the arguments
		if(string(argv[i]) == "-text"){
			cout<<"DO NOT RUN GFX"<<endl;
		}else if(string(argv[i]) == "-seed"){
			srand(atoi(argv[i]));
		}else if(string(argv[i]) == "-scriptfile"){
			file = string(argv[i+1]);
			/*TODO: Check if successfull open prior to assign?
			if(string(argv[i+1]).open()){
				file = string(argv[i+1]);
			}
			*/
		}else if(string(argv[i]) == "-startlevel"){
			default_level = atoi(argv[i+1]);
		}		
	}
	/*
	----- END COMMAND-LINE ARGUMENT HANDLING -----
	*/
    //----------------------------------------------------
    
    l = buildLevel(default_level, file);
    Board mainBoard(width, height, l->getLevel());
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
        
        else if (cmd == "levelup"){
            int lvl = l->getLevel();
            l = buildLevel(lvl+multiplier);
            mainBoard.levelUp(multiplier);
            
        }
        
        else if (cmd == "leveldown"){
            int lvl = l->getLevel();
            l = buildLevel(lvl-multiplier);
            mainBoard.LevelDown(multiplier);
        }
        
        else if (cmd == "restart"){
            int lvl;
            cout<<"Enter what Level would you like to start the new game at: ";
            cin >> lvl;
            if (lvl == 0){
                string file;
                cout<<"Enter the name of the sequence file you would like to use: ";
                cin >> file;
                l = buildLevel(lvl, file);
            }
            else {
                l = buildLevel(lvl);
            }
            mainBoard = Board(width, height, lvl);
            current = l->createBlock();
            next = l->createBlock();
        }
        
        else if (cmd == "error"){
            cout<<"Invalid Command"<<std::endl;
        }
        
        cout<<std::endl;
    }
    
    return 0;
}

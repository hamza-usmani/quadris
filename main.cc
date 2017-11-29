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
    int default_level = 0;
    string file = "test.txt";
    
    /* ----- COMMAND-LINE ARGUMENT HANDLING -----*/
    
	for (int i = 1; i<argc; ++i){
		if(string(argv[i]) == "-text"){
			cout<<"DO NOT RUN GFX"<<endl;
		}
        else if(string(argv[i]) == "-seed"){
			srand(atoi(argv[i+1]));
		}
        else if(string(argv[i]) == "-scriptfile"){
            ifstream tempfile{string(argv[i+1])};
			if(tempfile){
				file = string(argv[i+1]);
			}
            else{
                cout<<"Invalid file, exiting game";
                return 1;
            }
		}
        else if(string(argv[i]) == "-startlevel"){
			default_level = atoi(argv[i+1]);
		}		
	}
	/* ----- END COMMAND-LINE ARGUMENT HANDLING ----- */
    
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
        if (!mainBoard.canPlace(current)){
            cout<<"No Board space for new block. Game Over!"<<std::endl;
            return 1;
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
            l = buildLevel(lvl+multiplier, file);
            mainBoard.levelUp(multiplier);
            
        }
        
        else if (cmd == "leveldown"){
            int lvl = l->getLevel();
            l = buildLevel(lvl-multiplier, file);
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
                l = buildLevel(lvl, file);
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

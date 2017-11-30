#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "board.h"
#include "commands.h"

int width;
int height;
int highscore;
int default_level;
std::string file;
int seed;
int totalLinesCleared;
int totalTurns;

int main(int argc, const char * argv[]) {
    width = 11;
    height = 18;
    highscore = 0;
    default_level = 0;
    file = "sequence.txt";
    seed = 1;
    totalLinesCleared = 0;
    totalTurns = 0;
    
    Level *l;
    
    /* ----- COMMAND-LINE ARGUMENT HANDLING -----*/
	for (int i = 1; i<argc; ++i){
		if(string(argv[i]) == "-text"){
			cout<<"Quadris will now run in text-only mode."<<endl;
		}
        else if(string(argv[i]) == "-seed"){
            try{
                seed = stoi(argv[i+1]);
            }
            catch(...){
                seed = 1;
                cout<<"You entered an invalid seed number! The seed has been set to default Seed 1."<<std::endl;
            }
            srand(seed);
		}
        else if(string(argv[i]) == "-scriptfile"){
            ifstream tempfile{string(argv[i+1])};
			if(tempfile){
				file = string(argv[i+1]);
			}
            else{
                cout<<"You entered an invalid script file, the game will now exit."<<std::endl;
                return 1;
            }
		}
        else if(string(argv[i]) == "-startlevel"){
            try{
                default_level = stoi(argv[i+1]);
            }
            catch(...){
                default_level = 0;
                cout<<"You enetered an invalid Level. The game will run in default Level 0."<<endl;
            }
		}		
	}
    
    l = buildLevel(default_level, file);
    Board mainBoard(width, height, l->getLevel());
    Block *current = l->createBlock();
    Block *next = l->createBlock();

    while(true){
        if (totalTurns % 5 == 0){
            if (totalLinesCleared < 1){
                //mainBoard.addBlankBlock
            }
            totalLinesCleared = 0;
        }
        totalTurns++;
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
        
        
        if (cmd.length() == 1){
            mainBoard.eraseBlock(current);
            current = l->changeCurrentBlock(cmd);
            mainBoard.addBlock(current);
            cout<<mainBoard;
        }
        
        else if (cmd == "left") {
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
            if (lvl < 3 && l->getLevel() > 2) next->toggleHeavy();
        }
        
        else if (cmd == "leveldown"){
            int lvl = l->getLevel();
            l = buildLevel(lvl-multiplier, file);
            mainBoard.LevelDown(multiplier);
            if (lvl > 2 && l->getLevel() < 3) next->toggleHeavy();
        }
        
        else if (cmd == "restart"){
            int lvl;
            cout<<"Enter what Level (0-4) would you like to start the new game at: ";
            cin >> lvl;
            if (cin.fail()){
                lvl = 0;
                cout<<"You entered an invalid Level. The game will run in default Level 0."<<endl;
            }
            default_level = lvl;
            l = buildLevel(default_level, file);
            mainBoard = Board(width, height, default_level);
            current = l->createBlock();
            next = l->createBlock();
        }
        
        else if (cmd == "norandom"){
            vector<char> tmp;
            build_vector_from_file(tmp, file);
            l->randomOff(tmp);
            next = l->createBlock();
        }
        
        else if (cmd == "random"){
            l->randomOn();
            next = l->createBlock();
        }
        
        else if (cmd == "hint"){
            
        }
        
        else if (cmd == "sequence"){
            
        }
        
        else if (cmd == "error"){
            cout<<"Invalid Command"<<std::endl;
        }
        
        cout<<std::endl;
    }
    
    return 0;
}

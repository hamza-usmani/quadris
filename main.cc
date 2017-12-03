#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "board.h"
#include "commands.h"
#include "graphicsdisplay.h"

int width;
int height;
int curscore;
int highscore;
int default_level;
string file;
int seed;
int totalLinesCleared;
int totalTurns;

string macroFile;
int macroIndex;
vector<string> macros;
bool useMacro;

int main(int argc, const char * argv[]) {
    width = 11;
    height = 18;
    curscore = 0;
    highscore = 0;
    default_level = 0;
    file = "sequence.txt";
    seed = 1;
    totalLinesCleared = 0;
    totalTurns = 1;
    int windowsize = 600;
    bool textOnlyMode = false;
    
    macroFile = "";
    macroIndex = 0;
    
    Level *l;
    
    /* ----- COMMAND-LINE ARGUMENT HANDLING -----*/
	for (int i = 1; i<argc; ++i){
		if(string(argv[i]) == "-text"){
			cout<<"Quadris will now run in text-only mode."<<endl;
            textOnlyMode = true;
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
                cout<<"You entered an invalid Level. The game will run in default Level 0."<<endl;
            }
		}		
	}
    
    l = buildLevel(default_level, file);
    Board mainBoard(width, height, l->getLevel());
    GraphicsDisplay *display;
    
    if (!textOnlyMode){
        display = new GraphicsDisplay(width, height, windowsize);
        mainBoard.setGraphics(display);
    }
    
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
        
        if (useMacro){
            string curMacrocmd = macros.at(macroIndex);
            readMacroCommand(curMacrocmd, cmd, multiplier);
            macroIndex++;
            if (macroIndex == macros.size()){
                useMacro = false;
            }
        }
        
        else{
            readCommand(cin, cmd, multiplier);
            if (cmd.empty()) break;
        }
        
        if (cmd.length() == 1){
            mainBoard.eraseBlock(current);
            Block *temp = current;
            current = l->changeCurrentBlock(cmd);
            delete temp;
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
                
                if (l->getLevel() == 4 && totalTurns % 5 == 0 && totalTurns != 0){
                    if (totalLinesCleared < 1){
                        mainBoard.addBlankBlock();
                    }
                    totalLinesCleared = 0;
                }
                
                totalTurns++;
            }
        }
        
        else if (cmd == "levelup"){
            Level *temp = l;
            totalLinesCleared = 0;
            totalTurns = 1;
            int lvl = l->getLevel();
            if (lvl+multiplier > 4){
                cout<<"Invalid Level multiplier! The game will run at maximum Level 4."<<endl;
                l = buildLevel(4, file);
                mainBoard.levelUp(4-lvl);
            }
            else{
                l = buildLevel(lvl+multiplier, file);
                mainBoard.levelUp(multiplier);
            }
            if (lvl < 3 && l->getLevel() > 2) next->toggleHeavy();
            delete temp;
        }
        
        else if (cmd == "leveldown"){
            Level *temp = l;
            totalLinesCleared = 0;
            totalTurns = 1;
            int lvl = l->getLevel();
            if (lvl-multiplier < 0){
                cout<<"Invalid Level multiplier! The game will run at minimum Level 0."<<endl;
                l = buildLevel(0, file);
                mainBoard.LevelDown(lvl);
            }
            else{
                l = buildLevel(lvl-multiplier, file);
                mainBoard.LevelDown(multiplier);
            }
            if (lvl > 2 && l->getLevel() < 3) next->toggleHeavy();
            delete temp;
        }
        
        else if (cmd == "restart"){
            Level *temp = l;
            int lvl;
            cout<<"Enter what Level (0-4) would you like to start the new game at: ";
            cin >> lvl;
            if (cin.fail()){
                lvl = 0;
                cout<<"You entered an invalid Level. The game will run in default Level 0."<<endl;
            }
            curscore = 0;
            totalLinesCleared = 0;
            totalTurns = 1;
            
            default_level = lvl;
            l = buildLevel(default_level, file);
            mainBoard.setGraphics(nullptr);
            mainBoard.deleteDisplay();
            mainBoard = Board(width, height, default_level);
            if (!textOnlyMode) mainBoard.setGraphics(display);

            current = l->createBlock();
            next = l->createBlock();

            delete temp;
        }
        
        else if (cmd == "norandom"){
            vector<char> tmp;
            if (buildVector<char>(tmp, file)){
                l->randomOff(tmp);
                next = l->createBlock();
            }
            else{
                cout<<"You entered an invalid file. The game will continue as normal."<<endl;
                continue;
            }
        }
        
        else if (cmd == "random"){
            l->randomOn();
            Block *temp = next;
            next = l->createBlock();
            delete temp;
        }
        
        else if (cmd == "hint"){
            vector<Pos> hint = mainBoard.getHint(current);            
            cout<<mainBoard<<"Enter anything to proceed and hide hint"<<endl;
            char tmp;
            cin >> tmp;
            mainBoard.clearHint(hint);
        }
        
        else if (cmd == "sequence"){
            macros.clear();
            
            if (buildVector<string>(macros, macroFile)){
                macroIndex = 0;
                useMacro = true;
            }
            else{
                cout<<"You entered an invalid file. The game will continue as normal."<<endl;
                continue;
            }
        }
        
        else if (cmd == "error"){
            cout<<"Invalid Command"<<std::endl;
        }
        
        else if (cmd == "quit"){
            break;
        }
        
        cout<<std::endl;
    }
    cout<<"Game Over!"<<std::endl;
    delete l;
    mainBoard.deleteDisplay();
    
    return 0;
}

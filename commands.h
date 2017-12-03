#ifndef CMD_H
#define CMD_H

#include <string>
#include <iostream>
#include "Level.h"
#include "Level_0.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Level_4.h"
#include "global.h"

using namespace std;

std::vector<std::string> Master_CMD_List = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart", "hint", "quit"};

template <typename T> bool buildVector(std::vector<T> &my_vect, std::string f_name){
    std::ifstream my_file (f_name);
    
    if (!my_file.good()) return false;
    
    if (my_file.is_open()){
        T x;
        while (my_file >> x){
            my_vect.emplace_back(x);
        }
        my_file.close();
    }
    return true;
}
    

Level *buildLevel(int n, string f_name){
    switch (n){
        case 1:
            return new Level_1();
            break;
        case 2:
            return new Level_2();
            break;
        case 3:
            return new Level_3();
            break;
        case 4:
            return new Level_4();
            break;
        default:
            vector<char> sequence_txt_vector;
            buildVector<char>(sequence_txt_vector, f_name);
            return new Level_0(sequence_txt_vector);
            break;
    }
}

std::string autofill(std::string &user_cmd){
	std::vector<std::string> Workng_CMD_List = Master_CMD_List;
	for (int i = 0; i < user_cmd.size(); i++){
		for (int j = 0; j < Workng_CMD_List.size(); j++){
			if (Workng_CMD_List.at(j).at(i) != user_cmd.at(i)){
				Workng_CMD_List.erase(Workng_CMD_List.begin() + j);
				j--;
			}
		}
	}
	if (Workng_CMD_List.size() == 1){
		return Workng_CMD_List.at(0);
	}
    else{
		return "error";
	}
}


void readCommand(istream &in, string &cmd, int &multiplier){
    string user_cmd;
    string numString;
    string tempFile;
    in >> user_cmd;
    if (in.eof() || user_cmd.empty()){
        cmd = "";
        return;
    }
    if (user_cmd.length() == 1 && (user_cmd == "I" || user_cmd == "i" || user_cmd == "J" || user_cmd == "j" || user_cmd == "L" || user_cmd == "l" || user_cmd == "O" || user_cmd == "o" || user_cmd == "S" || user_cmd == "s" || user_cmd == "Z" || user_cmd == "z" || user_cmd == "T" || user_cmd == "t")){
        cmd = user_cmd;
        return;
    }
    
    bool letterFound = false;
    
    for (int i=0; i< user_cmd.length(); i++){
        if (!letterFound && isdigit(user_cmd[i])){
            numString+= user_cmd[i];
        }
        else {
            user_cmd = user_cmd.substr(i);
            break;
        }
    }
    
    if (!numString.empty()) multiplier = stoi(numString);
    cmd = autofill(user_cmd);
    
    if (cmd == "sequence" || cmd == "norandom") in >> tempFile;
    
    if (!tempFile.empty() && cmd == "norandom") file = tempFile;
    if (!tempFile.empty() && cmd == "sequence") macroFile = tempFile;
}


//reading from macro vector
void readMacroCommand(string macroCmd, string &cmd, int &multiplier){
    string numString;
    
    if (macroCmd.length() == 1 && (macroCmd == "I" || macroCmd == "i" || macroCmd == "J" || macroCmd == "j" || macroCmd == "L" || macroCmd == "l" || macroCmd == "O" || macroCmd == "o" || macroCmd == "S" || macroCmd == "s" || macroCmd == "Z" || macroCmd == "z" || macroCmd == "T" || macroCmd == "t")){
        cmd = macroCmd;
        return;
    }
    
    bool letterFound = false;
    for (int i=0; i< macroCmd.length(); i++){
        if (!letterFound && isdigit(macroCmd[i])){
            numString+= macroCmd[i];
        }
        else {
            macroCmd = macroCmd.substr(i);
            break;
        }
    }
    
    if (!numString.empty()) multiplier = stoi(numString);
    cmd = autofill(macroCmd);
}


#endif

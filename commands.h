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

using namespace std;

//GLOBAL VARIABLES
const int width = 11;
const int height = 18;
int default_level = 0;
string file = "sequence.txt";
int seed = 1;

std::vector<std::string> Master_CMD_List = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart", "hint"};

void build_vector_from_file(std::vector<char> &my_vect, std::string f_name){
    std::ifstream my_file (f_name);
    if (my_file.is_open()){
        char x;
        while (my_file >> x){
            my_vect.emplace_back(x);
        }
        my_file.close();
    }
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
            build_vector_from_file(sequence_txt_vector, f_name);
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
    
    if (user_cmd.length() == 1 && (user_cmd == "I" || user_cmd == "J" || user_cmd == "L" || user_cmd == "O" || user_cmd == "S" || user_cmd == "Z" || user_cmd == "T")){
        cmd = user_cmd;
        return;
    }
    if (user_cmd == "sequence" || user_cmd == "norandom") in >> tempFile;
    
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
    
    file = tempFile;
    if (!numString.empty()){
        multiplier = stoi(numString);
    }
    cmd = autofill(user_cmd);
}

#endif

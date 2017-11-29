#ifndef CMD_H
#define CMD_H

#include <string>
#include <iostream>
using namespace std;

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
    
    in >> user_cmd;
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
    
    if (!numString.empty()){
        multiplier = stoi(numString);
    }
    cmd = autofill(user_cmd);
}

#endif

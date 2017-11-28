#ifndef CMD_H
#define CMD_H

#include <fstream>
#include <string>
#include <iostream>

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

// TODO: See how spaces are to be pased in
int strip_getNum(std::string &in){
	// ie 4rig 5  
	bool debug = false;


	bool enter_char = false;
	std::string temp;
	int temp_cursor = 0;
	int multiplier;

	if (debug) std::cout<<"input is: "<<in<<std::endl;
	for (int i = 0; i<in.size(); ++i){
		if (debug) std::cout<<"Working on "<<in.at(i)<<std::endl;
		if (in.at(i) == ' ') continue; //ignore WS
		if (in.at(i) <= 57 && in.at(i) >= 48){ //is_num
			if (debug) std::cout<<"-->Detect num"<<std::endl;
			if (!enter_char){
				multiplier = in.at(i) - '0';
				if (debug) std::cout<<"multiplier set to: "<<multiplier<<std::endl;
			} else{
				//TODO: Throw exception
				return 99;
			}

		}else{
			if (debug) std::cout<<"-->detect char"<<std::endl;
			// if we find a letter, build the new_str
			enter_char = true;
			temp += in.at(i);
			temp_cursor++;
		}
	}
	in = temp;
	return multiplier;
}

// IMPORTANT TODO: Handle lefttt (overflow)
std::string autofill(std::string &in){
	std::vector<std::string> Master_CMD_List = {"left", "right", "down", "clockwise", "counterclockwise", "drop"}; // This represents the list of possible commands
	std::vector<std::string> Workng_CMD_List = Master_CMD_List; 

	// we go through each char in the given cmd, axing potential candiates as we go
	for (int i = 0; i < in.size(); ++i){
		for (int j = 0; j < Workng_CMD_List.size(); ++j){ //for each char, we check if it exists in that entry
			if (Workng_CMD_List.at(j).at(i) != in.at(i)){
				Workng_CMD_List.erase(Workng_CMD_List.begin() + j);
				j--;
			}
		}
	}
	// Done going through the given input, at this point we should have it narrowed down
	if (Workng_CMD_List.size() == 1){
		return Workng_CMD_List.at(0);
	}else{
		return "ERROR";
	}
}

#endif

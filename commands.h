#ifndef CMD_H
#define CMD_H

#include <fstream>
#include <string>

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

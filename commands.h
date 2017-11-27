#ifndef CMD_H
#define CMD_H

#include <fstream>

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

#endif

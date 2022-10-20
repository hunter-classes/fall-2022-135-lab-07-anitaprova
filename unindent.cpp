#include <iostream>
#include <string>
#include <cctype>

std::string removeLeadingSpaces(std::string line){
        std::string new_string;
        int i = 0;
        char c;

        while (i < line.size()){
                c = line[i];
                if(!isspace(c)) {
                        break;
                }
                i++;
        }
        new_string = line.substr(i);

        return new_string;
}

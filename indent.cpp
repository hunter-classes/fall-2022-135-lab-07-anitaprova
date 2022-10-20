#include <iostream>
#include <string>

int countChar(std::string line, char c) {
        int count = 0;

        for(int i = 0; i < line.length(); i++){
                if(line[i] == c ){
                        count++;
                }
        }

        return count;
}

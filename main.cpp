#include <iostream>
#include <string>
#include <fstream>
#include "unindent.h"
#include "indent.h"

int main() {
	std::cout << removeLeadingSpaces("           int c = -9;") << std::endl;
	std::cout << countChar("for(int i = 0; i < 10; i++){", '{') << std::endl;


	std::ifstream in_file;
	in_file.open("bad-code.cpp");
	if (in_file.fail()) { 
		std::cout << "Failed" << std::endl;
		return -1; 
	}

	std::ofstream out_file;
	out_file.open("unindented-code.cpp");
	if (out_file.fail()) { 
		std::cout << "Failed" << std::endl;
		return -1; 
	}	

	std::string line;
	while(getline(in_file, line)){
		out_file << removeLeadingSpaces(line) << std::endl;
	}

	in_file.close();
	out_file.close();

	in_file.open("unindented-code.cpp");
	out_file.open("good-code.cpp");

	int open, close, block = 0;
	while(getline(in_file, line)) {

		std::string tabs = "";
		for (int i = 0; i < block; i++) {
			if(line == "}") {
				i++;
				if(i >= block) {break;}
			}
			tabs += '\t';
		}
		out_file << tabs << line << std::endl;
		
		open += countChar(line, '{');
		close += countChar(line, '}');
		block = open - close;
	}
		
	return 0;
}

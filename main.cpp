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

	int open = 0;
	int close = 0;
	int block = 0;
	
	while(getline(in_file, line)) {
		block = open - close;
		open += countChar(line, '{');
		close += countChar(line, '}');

		std::string tabs = "";
		if(line[0] == '}') {
			for (int i = 0; i < block - 1; i++) {
				tabs += '\t';
			}
		}
		else {
			for (int i = 0; i < block; i++) {
				tabs += '\t';
			}
			
		}
		out_file << tabs << line << std::endl;
		
		std::cout << open << " " << close << " " << block << " " << " END" <<std::endl;
	}
		
	return 0;
}

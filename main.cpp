//Comment for the Pull Request Lab
#include <iostream>
#include <string>
#include <fstream>
#include "unindent.h"
#include "indent.h"

int main() {
	std::cout << removeLeadingSpaces("           int c = -9;") << std::endl;
	std::cout << countChar("for(int i = 0; i < 10; i++){", '{') << std::endl;

	std::ifstream in_file;
	std::ofstream out_file;
	in_file.open("bad-code.cpp");
	if (in_file.fail()) {
		std::cout << "Failed" << std::endl;
		return -1;
	}
	out_file.open("good-code.cpp");
	if (out_file.fail()) {
		std::cout << "Failed" << std::endl;
		return -1;
	}
	
	int open = 0;
	int close = 0;
	int block = 0;

	std::string line;	
	while(getline(in_file, line)) {
		std::string str = removeLeadingSpaces(line);
		block = open - close;
		open += countChar(line, '{');
		close += countChar(line, '}');

		std::string tabs = "";
		if(str[0] == '}') {
			for (int i = 0; i < block - 1; i++) {
				tabs += '\t';
			}
		}
		else {
			for (int i = 0; i < block; i++) {
				tabs += '\t';
			}
			
		}
		out_file << tabs << str << std::endl;
	}
		
	return 0;
}

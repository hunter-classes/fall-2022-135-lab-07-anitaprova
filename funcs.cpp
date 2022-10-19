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

int countChar(std::string line, char c) {
	int count = 0;
	
	for(int i = 0; i < line.length(); i++){
		if(line[i] == c ){
			count++;
		}
	}

	return count;
}

std::string indent(std::string line){
	int block, open, close = 0;
	std::string indented;
	
	int i = 0; 
	while(i < line.length()) {
		open += countChar(line, '{');
		close += countChar(line, '}');
		block = open - close;
		for(int j = 0; i < block; j++)
		{
			indented += '\t';	
		}
		indented += line;	
		i++;		
	}
	
	return indented;
}


#include "readFile.hpp"

string* readFile(char* fileName){
	ifstream read;

	read.open(fileName);

	string* buffer = new string;
	char tmp;

	for(int i = 0; i < SIZE; i++){
		read >> tmp;
		buffer->push_back(tmp);
	}

	read.close();

	return buffer;
}
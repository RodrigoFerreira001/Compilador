#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

class Buffer{
private:
	int* maxSize;
	int* bI;
	int* currentLine;
	int* currentPos;
	int* filePos;
	string* buffer;
	void reload(ifstream* read);
	bool readyToReload(ifstream* read);
	bool fileIsEmpty(ifstream* read);
	bool bufferIsFull();


public:
	Buffer();
	Buffer(int size, ifstream* read);
	~Buffer();

	char getNextChar(ifstream* read);
	bool EOB(ifstream* read);
	void ungetChar();
	int getCurrentLine();
	int getCurrentPos();
};
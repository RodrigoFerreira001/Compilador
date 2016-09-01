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
	string* fileName;
	string* buffer;
	void reload();
	bool readyToReload();
	bool fileIsEmpty();
	bool bufferIsFull();


public:
	Buffer(int size, char* file);
	~Buffer();

	char getNextChar();
	bool eob();
	void ungetChar();
	int getCurrentLine();
	int getCurrentPos();
};

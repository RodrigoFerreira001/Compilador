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
	int* actualSize;
	int* numLines;
	int* filePos;

	string* buffer;
	string* strTmp;

	ifstream read;

public:
	Buffer();
	Buffer(int size, char* fileName);
	~Buffer();

	void setMaxSize(int maxSize);
	void setActualSize(int ActualSize);
	void setNumLines(int NumLines);

	int getMaxSize();
	int getActualSize();
	int getNumLines();
	string getBuffer();
	char getNextChar();

	void reload();
	void print();
	bool EOB();
};
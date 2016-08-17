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

public:
	Buffer();
	Buffer(int size);
	~Buffer();

	void setMaxSize(int maxSize);
	void setActualSize(int ActualSize);
	void setNumLines(int NumLines);
	int getMaxSize();
	int getActualSize();
	int getNumLines();
	string getBuffer();

	void load(char* fileName);
	void print();
	int isFull();
};
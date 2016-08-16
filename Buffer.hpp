#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Buffer{
private:
	int* size;
	int* line;
	string* buffer;

public:
	Buffer();
	Buffer(int size);
	~Buffer();

	void setSize(int sz);
	int getSize();
	void load(char* fileName);
	void print();
};
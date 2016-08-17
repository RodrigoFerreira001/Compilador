#include "Buffer.hpp"


// Standard constructor
Buffer::Buffer() {
	this->maxSize = new int;
	this->actualSize = new int;
	this->numLines = new int;
	this->buffer = new string;
}


// Constructor with parameters
Buffer::Buffer(int maxSize) {
	this->maxSize = new int;
	*(this->maxSize) = maxSize;

	this->actualSize = new int;
	*(this->actualSize) = 0;

	this->numLines = new int;
	*(this->numLines) = 0;
	
	this->buffer = new string();
	this->buffer->resize(maxSize);
}


// Destructor
Buffer::~Buffer() {
	delete this->maxSize;
	delete this->actualSize;
	delete this->numLines;
	delete this->buffer;
}


// Setters
void Buffer::setMaxSize(int maxSize) {
	*(this->maxSize) = maxSize;
}

void Buffer::setActualSize(int actualSize) {
	*(this->actualSize) = actualSize;
}

void Buffer::setNumLines(int numLines) {
	*(this->numLines) = numLines;
}


// Getters
int Buffer::getMaxSize() {
	return *(this->maxSize);
}

int Buffer::getActualSize() {
	return *(this->actualSize);
}

int Buffer::getNumLines() {
	return *(this->numLines);
}

string Buffer::getBuffer() {
	return *(this->buffer);
}


// Methods
void Buffer::load(char* fileName) {
	
	ifstream read;
	read.open(fileName);
	// Print an error and exit
	if (!read) {
        cerr << "ERROR: Input file could not be found!" << endl;
        exit(EXIT_FAILURE);
    }

    char tmp;
	while(read.get(tmp)){
		//if(tmp == '\n')
			
		cout << tmp;
	}

	read.close();
}

void Buffer::print(){
	cout << *(this->buffer) << endl;
}

int Buffer::isFull(){

}
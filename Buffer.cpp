#include "Buffer.hpp"

// Standard constructor
Buffer::Buffer() {
	this->size = new int;
	this->line = new int;
	this->buffer = new string;
}

// Constructor with parameters
Buffer::Buffer(int size) {
	this->size = new int;
	*(this->size) = size;

	this->line = new int;
	*(this->line) = 0;
	
	this->buffer = new string(size, ' ');
}

Buffer::~Buffer() {
	delete this->size;
	delete this->buffer;
}

void Buffer::setSize(int sz) {
	*(this->size) = sz;
}

int Buffer::getSize() {
	return *(this->size);
}

void Buffer::load(char* fileName) {
	ifstream read;

	read.open(fileName);

	char tmp;

	for(int i = 0; i < *(this->size); ++i){
		read >> tmp;
		if(tmp == '\n' || tmp == '\t' || tmp == ' ')
			cout << "OLHA EU AQUI MÃE";
		this->buffer->push_back(tmp);
	}

	read.close();
}

void Buffer::print(){
	cout << *(this->buffer) << endl;
}
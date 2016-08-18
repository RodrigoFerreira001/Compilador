#include "Buffer.hpp"

// Standard constructor
Buffer::Buffer() {
	this->maxSize = new int;
	this->actualSize = new int;
	this->numLines = new int;
	this->buffer = new string;
}

// Constructor with parameters
Buffer::Buffer(int maxSize, char* fileName) {
	this->maxSize = new int;
	*(this->maxSize) = maxSize;

	this->actualSize = new int;
	*(this->actualSize) = 0;

	this->numLines = new int;
	*(this->numLines) = 0;
	
	this->buffer = new string();
	this->strTmp = new string();

	this->read.open(fileName);
	// Print an error and exit
	if (!read) {
        cerr << "ERROR: Input file could not be found!" << endl;
        exit(EXIT_FAILURE);
 	}

    char tmp;
    int aux = 0, capacity = 0;

    // && (*(this->actualSize) < (*(this->maxSize) ))

    // cout << "ENTREI AQUI" << endl;

	do {
		while(read.get(tmp)) {
			if(tmp != '\n' && tmp != '\t' && tmp != ' ') {
				this->strTmp->insert(aux++, 1, tmp);		
			} else {
				if(tmp == '\n' )
					(*(this->numLines))++;
				this->strTmp->insert(aux++, 1, tmp);
				break;
			}
		}

		capacity = (*(this->maxSize)) - (*(this->actualSize));
		if(capacity < this->strTmp->length())
			break;

		this->buffer->insert(*(this->actualSize), *(this->strTmp));
		(*(this->actualSize)) += aux;
		this->strTmp->clear();
		aux = 0;
	} while(!read.eof());
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
void Buffer::reload() {
	char tmp;
	int aux = 0, capacity = 0;

	if(this->strTmp->length() > 0) {
		capacity = (*(this->maxSize)) - (*(this->actualSize));
		if(capacity < this->strTmp->length())
			return;
		else {
			this->buffer->insert(*(this->actualSize), *(this->strTmp));
			(*(this->actualSize)) += this->strTmp->length();
			this->strTmp->clear();
		}
	}

	do {
		while(read.get(tmp)) {
			if(tmp != '\n' && tmp != '\t' && tmp != ' ') {
				this->strTmp->insert(aux++, 1, tmp);		
			} else {
				if(tmp == '\n' )
					(*(this->numLines))++;
				this->strTmp->insert(aux++, 1, tmp);
				break;
			}
		}

		capacity = (*(this->maxSize)) - (*(this->actualSize));
		if(capacity < this->strTmp->length())
			break;

		this->buffer->insert(*(this->actualSize), *(this->strTmp));
		(*(this->actualSize)) += this->strTmp->length();
		this->strTmp->clear();
		aux = 0;
	} while(!read.eof());
}

char Buffer::getNextChar() {
	if(!this->EOB()){
		if(this->buffer->length() == 0) {
			this->reload();
		}
		char tmp;
		tmp = (this->buffer->at(0));
		this->buffer->erase(0, 1);
		(*(this->actualSize))--;
		return tmp;
	}
}

void Buffer::print(){
	cout << *(this->buffer) << endl;
	cout << this->buffer->length() << endl;
	cout << *(this->actualSize) << endl;
}

bool Buffer::EOB(){
	if(this->read.eof() && this->strTmp->length() == 0 && this->buffer->length() == 0){
		read.close();
		return true;
	}
	else
		return false;
}
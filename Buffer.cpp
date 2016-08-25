#include "Buffer.hpp"

// Standard constructor
Buffer::Buffer() {
	this->maxSize = new int;
	this->bI = new int;
	this->currentLine = new int;
	this->currentPos = new int;
	this->filePos = new int;
	this->buffer = new string();
}

// Constructor with parameters
Buffer::Buffer(int maxSize, ifstream* read) {
	this->maxSize = new int;
	*(this->maxSize) = maxSize;
	
	this->bI = new int;
	*(this->bI) = 0;

	this->currentLine = new int;
	*(this->currentLine) = 1;

	this->currentPos = new int;
	*(this->currentPos) = 1;

	this->filePos = new int;
	*(this->filePos) = 0;

	this->buffer = new string();

    this->reload(read);
}

// Destructor
Buffer::~Buffer() {
	delete this->maxSize;
	delete this->bI;
	delete this->currentLine;
	delete this->currentPos;
	delete this->filePos;
	delete this->buffer;

}


// ======================================================================
// Public Methods
char Buffer::getNextChar(ifstream* read) {
	if(((this->fileIsEmpty(read)) && (*(this->bI)) == this->buffer->length())) {
		return '\0';
	} else {
		if(this->readyToReload(read)) {
			this->buffer->erase(0, *(bI) - 1);
			*(this->bI) = this->buffer->length();
			this->reload(read);
		}
		char tmp;
		tmp = (this->buffer->at(*(this->bI)));

		if(tmp == '\n'){
			(*(this->currentLine))++;
			(*(this->currentPos)) = 0;
		}
		
		(*(this->currentPos))++;
		(*(this->bI))++;
		
		return tmp;
	}
}

void Buffer::ungetChar(){
	(*(this->bI))--;
}

bool Buffer::EOB(ifstream* read){
	if(fileIsEmpty(read) && (*(this->bI)) == this->buffer->length())
		return true;
	else
		return false;
}

int Buffer::getCurrentLine(){
	return *(this->currentLine);	
}

int Buffer::getCurrentPos(){
	return *(this->currentPos);
}

// ======================================================================
// Private Methods
void Buffer::reload(ifstream* read) {
	char tmp;

	read->seekg((*(this->filePos)));
    while(!this->bufferIsFull()) {
    	if(!read->get(tmp))
    		break;
    	this->buffer->push_back(tmp);
    	(*(this->filePos))++;
    }
}

bool Buffer::bufferIsFull(){
	if(this->buffer->length() < *(this->maxSize))
		return false;
	else
		return true; 
}

bool Buffer::readyToReload(ifstream* read) {
	if(*(this->bI) == *(this->maxSize) && !this->fileIsEmpty(read))
		return true;
	else
		return false;
}


bool Buffer::fileIsEmpty(ifstream* read){
	read->seekg(0, ios::end);
	int length = read->tellg();

	if(*(this->filePos) < length){
		return false;
	} else {
		return true;
	}
}


#include "Buffer.hpp"

// Constructor with parameters
Buffer::Buffer(int maxSize, char* file) {
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
	this->fileName = new string(file);

    this->reload();
}

// Destructor
Buffer::~Buffer() {
	delete this->maxSize;
	delete this->bI;
	delete this->currentLine;
	delete this->currentPos;
	delete this->filePos;
	delete this->buffer;
	delete this->fileName;
}


// ======================================================================
// Public Methods
char Buffer::getNextChar() {

	if(((this->fileIsEmpty()) && (*(this->bI)) == this->buffer->length())) {
		return '\0';
	} else {
		if(this->readyToReload()) {
			this->buffer->erase(0, *(bI) - 1);
			*(this->bI) = this->buffer->length();
			this->reload();
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
	if((*(this->bI)) > 0){
		(*(this->bI))--;
		(*(this->currentPos))--;
	}

}

void Buffer::ungetLine(int line){
	(*(this->currentLine)) -= line;

}


bool Buffer::eob(){
	if(fileIsEmpty() && (*(this->bI)) == this->buffer->length())
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


void Buffer::removeLine(){
	(*(this->currentLine))--;
}

// ======================================================================
// Private Methods
void Buffer::reload() {
	char tmp;

	ifstream read;
	read.open(this->fileName->c_str());

	read.seekg((*(this->filePos)));
    while(!this->bufferIsFull()) {
    	if(!read.get(tmp))
    		break;
    	this->buffer->push_back(tmp);
    	(*(this->filePos))++;
    }

    read.close();
}

bool Buffer::bufferIsFull(){
	if(this->buffer->length() < *(this->maxSize))
		return false;
	else
		return true;
}

bool Buffer::readyToReload() {
	if(*(this->bI) == *(this->maxSize) && !this->fileIsEmpty())
		return true;
	else
		return false;
}


bool Buffer::fileIsEmpty(){
	ifstream read;
	read.open(this->fileName->c_str());

	read.seekg(0, ios::end);
	int length = read.tellg();

	read.close();

	if(*(this->filePos) < length){
		return false;
	} else {
		return true;
	}
}

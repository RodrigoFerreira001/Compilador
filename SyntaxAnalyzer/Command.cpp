#include "Command.hpp"

Command::Command(string c_type){
	children = new vector<Command*>;
	this->c_type = new string(c_type);
}

Command::~Command(){
	delete children;
	delete c_type;
}

vector<Command*>* Command::get_children(){
	return children;
}

string Command::get_c_type(){
	return *(this->c_type);
}

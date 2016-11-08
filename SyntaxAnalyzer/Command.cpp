#include "Command.hpp"

Command::Command(){
	children = new vector<Command*>;
	this->type_class = "COMMAND";
}

Command::~Command(){
	delete children;
}

vector<Command*>* Command::get_children(){
	return children;
}

string Command::get_type_name(){
	return this->type_class;
}

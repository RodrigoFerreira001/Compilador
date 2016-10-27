#include "Command.hpp"

Command::Command(){
	children = new vector<Command*>;
}

Command::~Command(){
	delete children;
}

vector<Command*>* Command::get_children(){
	return children;
}

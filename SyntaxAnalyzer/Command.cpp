#include "Command.hpp"

Command::Command(){
	children = new vector<Command*>;
}

Command::~Command(){
	delete children;
}

Command::append_child(Command *c){
	children->push_back(c);
}

vector<Command*>* Command::get_children(){
	return children;
}

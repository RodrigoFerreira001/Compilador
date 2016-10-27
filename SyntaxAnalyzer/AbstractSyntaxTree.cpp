#include "AbstractSyntaxTree.hpp"

AbstractSyntaxTree::AbstractSyntaxTree(){
	declarations = new vector<Declaration>;
	commands = new vector<Command>;
}

AbstractSyntaxTree::~AbstractSyntaxTree(){
	delete declarations;
	delete commands;
}

vector<Declaration>* AbstractSyntaxTree::get_declarations(){
	return declarations;
}

vector<Command>* AbstractSyntaxTree::get_commands(){
	return commands;
}

#include "AbstractSyntaxTree.hpp"

AbstractSyntaxTree::AbstractSyntaxTree(){
	declarations = new vector<Declaration>;
	commands = new vector<Command>;
}

AbstractSyntaxTree::~AbstractSyntaxTree(){
	delete declarations;
	delete commands;
}

void AbstractSyntaxTree::set_declarations(vector<Declaration>* declarations){
	*(this->declarations) = declarations;
}

void AbstractSyntaxTree::set_commands(vector<Command>* commands){
	*(this->commands) = commands;
}

vector<Declaration>* AbstractSyntaxTree::get_declarations(){
	return declarations;
}

vector<Command>* AbstractSyntaxTree::get_commands(){
	return commands;
}

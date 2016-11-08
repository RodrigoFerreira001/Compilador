#include "While.hpp"

While::While(Expr* e, Command* c_true, string c_type) : Command(c_type){
	this->e = e;
	this->c_true = c_true;
}

While::~While(){
	delete e;
	delete c_true;
}

Expr* While::get_expr(){
	return this->e;
}

Command* While::get_c_true(){
	return this->c_true;
}

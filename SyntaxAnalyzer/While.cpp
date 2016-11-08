#include "While.hpp"

While::While(){

}

While::While(Expr* e, Command* c_true){
	this->type_class = "WHILE";
	this->e = e;
	this->c_true = c_true;
}

While::~While(){

}

Expr* While::get_expr(){
	return this->e;
}

Command* While::get_c_true(){
	return this->c_true;
}

string While::get_type_name(){
	return this->type_class;
}

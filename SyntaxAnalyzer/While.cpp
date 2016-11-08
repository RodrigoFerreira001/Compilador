#include "While.hpp"

While::While(){

}

While::While(Expr* e, Command* c_true){
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

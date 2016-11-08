#include "And.hpp"

And::And(Expr* e1, Expr* e2, string c_type) : Expr(c_type){
	this->e1 = e1;
	this->e2 = e2;
}

And::~And(){
	delete e1;
	delete e2;
}

Expr* And::get_expr_1(){
	return this->e1;
}

Expr* And::get_expr_2(){
	return this->e2;
}

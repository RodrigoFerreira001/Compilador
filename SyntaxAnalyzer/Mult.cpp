#include "Mult.hpp"

Mult::Mult(Expr* e1, Expr* e2, string c_type) : Expr(c_type){
	this->e1 = e1;
	this->e2 = e2;
}

Mult::~Mult(){
	delete e1;
	delete e2;
}

Expr* Mult::get_expr_1(){
	return this->e1;
}

Expr* Mult::get_expr_2(){
	return this->e2;
}

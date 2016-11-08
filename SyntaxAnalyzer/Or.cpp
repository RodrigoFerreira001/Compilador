#include "Or.hpp"

Or::Or(){

}

Or::Or(Expr* e1, Expr* e2, string c_type) : Expr(c_type){
	this->e1 = e1;
	this->e2 = e2;
}

Or::~Or(){

}

Expr* Or::get_expr_1(){
	return this->e1;
}

Expr* Or::get_expr_2(){
	return this->e2;
}

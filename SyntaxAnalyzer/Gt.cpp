#include "Gt.hpp"

Gt::Gt(){

}

Gt::Gt(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Gt::~Gt(){

}

Expr* Gt::get_expr_1(){
	return this->e1;
}

Expr* Gt::get_expr_2(){
	return this->e2;
}

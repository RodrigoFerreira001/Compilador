#include "Minus.hpp"

Minus::Minus(){

}

Minus::Minus(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Minus::~Minus(){

}

Expr* Minus::get_expr_1(){
	return this->e1;
}

Expr* Minus::get_expr_2(){
	return this->e2;
}

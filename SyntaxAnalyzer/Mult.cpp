#include "Mult.hpp"

Mult::Mult(){

}

Mult::Mult(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Mult::~Mult(){

}

Expr* Mult::get_expr_1(){
	return this->e1;
}

Expr* Mult::get_expr_2(){
	return this->e2;
}

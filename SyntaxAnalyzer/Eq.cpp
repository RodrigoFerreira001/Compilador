#include "Eq.hpp"

Eq::Eq(){

}

Eq::Eq(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Eq::~Eq(){

}

Expr* Eq::get_expr_1(){
	return this->e1;
}

Expr* Eq::get_expr_2(){
	return this->e2;
}

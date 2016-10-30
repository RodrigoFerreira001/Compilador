#include "Ne.hpp"

Ne::Ne(){

}

Ne::Ne(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Ne::~Ne(){

}

Expr* Ne::get_expr_1(){
	return this->e1;
}

Expr* Ne::get_expr_2(){
	return this->e2;
}

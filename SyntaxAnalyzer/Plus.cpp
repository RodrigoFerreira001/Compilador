#include "Plus.hpp"

Plus::Plus(){

}

Plus::Plus(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Plus::~Plus(){

}

Expr* Plus::get_expr_1(){
	return this->e1;
}

Expr* Plus::get_expr_2(){
	return this->e2;
}

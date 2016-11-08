#include "And.hpp"

And::And(){

}

And::And(Expr* e1, Expr* e2, string type) : Command(type){
	this->e1 = e1;
	this->e2 = e2;
}

And::~And(){

}

Expr* And::get_expr_1(){
	return this->e1;
}

Expr* And::get_expr_2(){
	return this->e2;
}

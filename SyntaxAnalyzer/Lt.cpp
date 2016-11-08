#include "Lt.hpp"

Lt::Lt(){

}

Lt::Lt(Expr* e1, Expr* e2, string c_type) : Expr(c_type){
	this->e1 = e1;
	this->e2 = e2;
}

Lt::~Lt(){

}

Expr* Lt::get_expr_1(){
	return this->e1;
}

Expr* Lt::get_expr_2(){
	return this->e2;
}

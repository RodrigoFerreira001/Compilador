#include "Lte.hpp"

Lte::Lte(){

}

Lte::Lte(Expr* e1, Expr* e2, string c_type) : Expr(c_type){
	this->e1 = e1;
	this->e2 = e2;
}

Lte::~Lte(){

}

Expr* Lte::get_expr_1(){
	return this->e1;
}

Expr* Lte::get_expr_2(){
	return this->e2;
}

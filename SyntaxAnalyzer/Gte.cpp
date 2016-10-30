#include "Gte.hpp"

Gte::Gte(){

}

Gte::Gte(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Gte::~Gte(){

}

Expr* Gte::get_expr_1(){
	return this->e1;
}

Expr* Gte::get_expr_2(){
	return this->e2;
}

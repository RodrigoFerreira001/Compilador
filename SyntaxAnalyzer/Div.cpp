#include "Div.hpp"

Div::Div(){

}

Div::Div(Expr* e1, Expr* e2){
	this->e1 = e1;
	this->e2 = e2;
}

Div::~Div(){

}

Expr* Div::get_expr_1(){
	return this->e1;
}

Expr* Div::get_expr_2(){
	return this->e2;
}

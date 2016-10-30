#include "Print.hpp"

Print::Print(){

}

Print::Print(Expr* e){
	this->e = e;
}

Print::~Print(){

}

Expr* Print::get_expr(){
	return this->e;
}

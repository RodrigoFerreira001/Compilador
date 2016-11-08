#include "Print.hpp"

Print::Print(Expr* e, string c_type) : Command(c_type){
	this->e = e;
}

Print::~Print(){
	delete e;
}

Expr* Print::get_expr(){
	return this->e;
}

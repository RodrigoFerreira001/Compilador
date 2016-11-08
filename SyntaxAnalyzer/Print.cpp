#include "Print.hpp"

Print::Print(Expr* e){
	this->type_class = "PRINT";
	this->e = e;
}

Print::~Print(){

}

Expr* Print::get_expr(){
	return this->e;
}

string Print::get_type_name(){
	return this->type_class;
}

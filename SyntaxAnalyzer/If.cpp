#include "If.hpp"

If::If(){

}

If::If(Expr* e, Command* c_true, Command* c_false, string c_type) : Command(c_type){
	this->e = e;
	this->c_true = c_true;
	this->c_false = c_false;
}

If::~If(){

}

Expr* If::get_expr(){
	return this->e;
}

Command* If::get_c_true(){
	return this->c_true;
}

Command* If::get_c_false(){
	return this->c_false;
}

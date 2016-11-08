#include "Attr.hpp"

Attr::Attr(){

}

Attr::Attr(Id* id, Expr* e, string c_type) : Command(c_type){
	this->id = id;
	this->e = e;
}

Attr::~Attr(){

}

Id* Attr::get_id(){
	return this->id;
}

Expr* Attr::get_expr(){
	return this->e;
}

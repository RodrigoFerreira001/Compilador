#include "Attr.hpp"

Attr::Attr(){

}

Attr::Attr(Id* id, Expr* e){
	this->type_class = "ATTR";
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

string Attr::get_type_name(){
	return this->type_class;
}

#include "Expr.hpp"

Expr::Expr(){
	type = new int;
	i_value = new int;
	f_value = new float;
	b_value = new bool;
}

Expr::Expr(int type, int i_value, float f_value, bool b_value){
	this->type = new int;
	this->i_value = new int;
	this->f_value = new float;
	this->b_value = new bool;

	*(this->type) = type;
	*(this->i_value) = i_value;
	*(this->f_value) = f_value;
	*(this->b_value) = b_value;
}

Expr::~Expr(){
	delete type;
	delete i_value;
	delete f_value;
	delete b_value;
}

void Expr::set_type(int type){
	*(this->type) = type;
}

int Expr::get_type(){
	return *(this->type);
}

void Expr::set_i_value(int i_value){
	*(this->i_value) = i_value;
}

int Expr::get_i_value(){
	return *(this->i_value);
}

void Expr::set_f_value(float f_value){
	*(this->f_value) = f_value;
}

float Expr::get_f_value(){
	return *(this->f_value);
}

void Expr::set_b_value(bool b_value){
	*(this->b_value) = b_value;
}

bool Expr::get_b_value(){
	return *(this->b_value);
}

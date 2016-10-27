#include "Temp.hpp"

int Temp::name_id = 0;

Temp::Temp(){
	name = new string("reg" + to_string(name_id));
	name_id++;
}

Temp::~Temp(){
	delete name;
}


string Temp::get_name(){
	return *name;
}

#include "Num.hpp"

Num::Num(TableEntry* table_entry, int type, string c_type) : Expr(c_type){
	this->table_entry = table_entry;
	this->type = new int(type);
}

Num::~Num(){
	delete type;
}

TableEntry* Num::get_table_entry(){
	return table_entry;
}

int Num::get_type(){
	return *type;
}

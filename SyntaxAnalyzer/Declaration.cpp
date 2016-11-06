#include "Declaration.hpp"

Declaration::Declaration(TableEntry* table_entry, bool is_var_decl, int type, Temp* temp){
	this->table_entry = table_entry;
	this->is_var_decl = new bool(is_var_decl);
	this->type = new int(type);
	this->temp = temp;
}

Declaration::Declaration(const Declaration& d){
	this->table_entry = table_entry;
	this->is_var_decl = new bool(*(d.is_var_decl));
	this->type = new int(*(d.type));
	this->temp = temp;
}

Declaration::~Declaration(){
	delete is_var_decl;
	delete type;
}

TableEntry* Declaration::get_table_entry(){
	return table_entry;
}

bool Declaration::get_is_var_decl(){
	return *is_var_decl;
}

int Declaration::get_type(){
	return *type;
}

Temp* Declaration::get_temp(){
	return temp;
}

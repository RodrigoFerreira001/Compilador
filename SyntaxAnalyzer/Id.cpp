#include "Id.hpp"

Id::Id(TableEntry* table_entry, bool is_l_value, bool is_var_decl, int type, Temp* temp){
	this->table_entry = table_entry;
	this->temp = temp;
	this->is_l_value = new bool(is_l_value);
	this->is_var_decl = new bool(is_var_decl);
	this->type = new int(type);
}

Id::~Id(){
	delete is_l_value;
	delete is_var_decl;
	delete type;
}

TableEntry* Id::get_table_entry(){
	return table_entry;
}

bool Id::get_is_l_value(){
	return *is_l_value;
}

bool Id::get_is_var_decl(){
	return *is_var_decl;
}

int Id::get_type(){
	return *type;
}

Temp* Id::get_temp(){
	return temp;
}

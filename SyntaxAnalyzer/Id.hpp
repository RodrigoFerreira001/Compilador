#pragma once
#include "Expr.hpp"
#include "../LexicalAnalyzer/TableEntry.hpp"
#include "Temp.hpp"

class Id : public Expr{
private:
	TableEntry* table_entry;
	bool* is_l_value;
	bool* is_var_decl;
	int* type;
	Temp* temp;
public:
	Id(TableEntry* table_entry, bool is_l_value, bool is_var_decl, int type, Temp* temp, string c_type);
	~Id();
	TableEntry* get_table_entry();
	bool get_is_l_value();
	bool get_is_var_decl();
	int get_type();
	Temp* get_temp();
};

#pragma once
#include "../LexicalAnalyzer/TableEntry.hpp"
#include "Temp.hpp"

class Declaration{
private:
	TableEntry* table_entry;
	bool* is_var_decl;
	int* type;
	Temp* temp;
public:
	Declaration();
	~Declaration();
	TableEntry* get_table_entry();
	bool get_is_var_decl();
	int get_type();
	Temp* get_temp();
};

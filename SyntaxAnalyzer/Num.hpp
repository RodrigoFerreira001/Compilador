#pragma once
#include "Expr.hpp"
#include "../LexicalAnalyzer/TableEntry.hpp"

class Num : public Expr{
private:
	TableEntry* table_entry;
	int* type;
public:
	Num(TableEntry* table_entry, int type);
	~Num()
	TableEntry* get_table_entry();
	int get_type();
};

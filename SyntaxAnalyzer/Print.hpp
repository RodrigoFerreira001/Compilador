#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Print : public Command{
public:
	Print(Expr* e);
	~Print();
	Expr* get_expr();
	string get_type_name();

private:
	Expr* e;
	string type_class;
};

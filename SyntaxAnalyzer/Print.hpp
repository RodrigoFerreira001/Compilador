#pragma once
#include "Command.hpp"

class Print : public Command{
public:
	Print();
	~Print();
	Expr* get_expr();

private:
	Expr* e;
};

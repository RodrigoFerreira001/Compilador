#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Print : public Command{
public:
	Print();
	Print(Expr* e);
	~Print();
	Expr* get_expr();

private:
	Expr* e;
};

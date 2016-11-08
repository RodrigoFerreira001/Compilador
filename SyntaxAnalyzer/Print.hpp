#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Print : public Command{
private:
	Expr* e;
	
public:
	Print(Expr* e, string c_type);
	~Print();
	Expr* get_expr();
};

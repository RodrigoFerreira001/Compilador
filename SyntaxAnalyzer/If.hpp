#pragma once
#include "Command.hpp"
#include "Id.hpp"

class If : public Command{
private:
	Expr* e;
	Command* c_true;
	Command* c_false;

public:
	If(Expr* e, Command* c_true, Command* c_false, string c_type);
	~If();
	Expr* get_expr();
	Command* get_c_true();
	Command* get_c_false();
};

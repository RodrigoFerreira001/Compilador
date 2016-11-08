#pragma once
#include "Command.hpp"
#include "Id.hpp"

class If : public Command{
public:
	If();
	If(Expr* e, Command* c_true, Command* c_false);
	~If();
	Expr* get_expr();
	Command* get_c_true();
	Command* get_c_false();

private:
	Expr* e;
	Command* c_true;
	Command* c_false;
};

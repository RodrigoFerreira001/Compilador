#pragma once
#include "Command.hpp"
#include "Id.hpp"

class While : public Command{
private:
	Expr* e;
	Command* c_true;

public:
	While();
	While(Expr* e, Command* c_true, string c_type);
	~While();
	Expr* get_expr();
	Command* get_c_true();
};
